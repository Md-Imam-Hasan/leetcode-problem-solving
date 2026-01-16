class Solution {
  public:
      int maximizeSquareArea(int m, int n, vector<int>& hFences,
                             vector<int>& vFences) {
          const int MOD = 1e9 + 7;
          if (m == n)
              return (long long)(m - 1) * (n - 1) % MOD;
          hFences.push_back(1);
          hFences.push_back(m);
          vFences.push_back(1);
          vFences.push_back(n);
  
          unordered_set<int> hdiff;
  
          int ans = -1;
  
          for (int i = 0; i < hFences.size() - 1; i++) {
              for (int j = i + 1; j < hFences.size(); j++) {
                  hdiff.insert(abs(hFences[j] - hFences[i]));
              }
          }
  
          for (int i = 0; i < vFences.size() - 1; i++) {
              for (int j = i + 1; j < vFences.size(); j++) {
                  int diff = abs(vFences[j] - vFences[i]);
                  if (hdiff.count(diff)) {
                      ans = max(ans, diff);
                  }
              }
          }
  
          return ans == -1 ? ans : (long long)ans * ans % MOD;
      }
  };