class Solution {
  public:
      int lcs(vector<int>& s1, vector<int>& s2) {
          int m = s1.size();
          int n = s2.size();
  
          // Initializing a matrix of size (m+1)*(n+1)
          vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  
          // Building dp[m+1][n+1] in bottom-up fashion
          for (int i = 1; i <= m; ++i) {
              for (int j = 1; j <= n; ++j) {
                  if (s1[i - 1] == s2[j - 1])
                      dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                  else
                      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
              }
          }
  
          // dp[m][n] contains length of LCS for s1[0..m-1]
          // and s2[0..n-1]
          return dp[m][n];
      }
      int calculateAscii(vector<int>& v, string s) {
          int sum = 0;
          for (char c : s) {
              int x = static_cast<int>(c);
              v.push_back(x);
              sum += x;
          }
          return sum;
      }
      int minimumDeleteSum(string s1, string s2) {
          vector<int> v1, v2;
          int v1sum = 0, v2sum = 0;
          v1sum = calculateAscii(v1, s1);
          v2sum = calculateAscii(v2, s2);
  
          int sum = lcs(v1, v2);
  
          return v1sum + v2sum - sum * 2;
      }
  };