class Solution {
  public:
      int minimumPairRemoval(vector<int>& nums) {
          int n = nums.size();
          if (n <= 1) return 0;
          
          vector<long long> val(nums.begin(), nums.end());
          vector<int> prv(n), nxt(n);
          for (int i = 0; i < n; i++) {
              prv[i] = i - 1;
              nxt[i] = i + 1;
          }
          
          int badPairs = 0;
          for (int i = 0; i + 1 < n; i++) {
              if (val[i] > val[i + 1]) badPairs++;
          }
          
          set<pair<long long, int>> pq;
          for (int i = 0; i + 1 < n; i++) {
              pq.insert({val[i] + val[i + 1], i});
          }
          
          int ops = 0;
          while (badPairs > 0) {
              auto [sum, i] = *pq.begin();
              pq.erase(pq.begin());
              
              int j = nxt[i];
              if (j >= n || nxt[j] == j) continue;
              
              int p = prv[i], k = nxt[j];
              if (p >= 0) pq.erase({val[p] + val[i], p});
              if (k < n) pq.erase({val[j] + val[k], j});
              
              if (p >= 0 && val[p] > val[i]) badPairs--;
              if (val[i] > val[j]) badPairs--;
              if (k < n && val[j] > val[k]) badPairs--;
              
              val[i] = val[i] + val[j];
              nxt[j] = j;
              nxt[i] = k;
              if (k < n) prv[k] = i;
              
              if (p >= 0 && val[p] > val[i]) badPairs++;
              if (k < n && val[i] > val[k]) badPairs++;
              
              if (p >= 0) pq.insert({val[p] + val[i], p});
              if (k < n) pq.insert({val[i] + val[k], i});
              
              ops++;
          }
          
          return ops;
      }
  };