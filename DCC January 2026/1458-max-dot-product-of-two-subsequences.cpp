class Solution {
  public:
      vector<int> a, b;
      vector<vector<int>> memo;
      int N, M;
      const int neg = -1e9;
      int run(int i, int j) {
          if (i == N || j == M) {
              return neg;
          }
  
          if (memo[i][j] != INT_MIN)
              return memo[i][j];
  
          int res = max({run(i + 1, j), run(i, j + 1), a[i] * b[j],
                         run(i + 1, j + 1) + a[i] * b[j]});
  
          return memo[i][j] = res;
      }
      int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          a = nums1;
          b = nums2;
          N = a.size(), M = b.size();
  
          memo.assign(N, vector<int>(M, INT_MIN));
          return run(0, 0);
      }
  };