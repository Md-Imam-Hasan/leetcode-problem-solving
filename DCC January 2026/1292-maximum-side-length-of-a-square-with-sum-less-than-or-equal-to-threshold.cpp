class Solution {
  public:
      bool isMagicSquare(vector<vector<int>>& grid, int x, int y, int size,
                         int target) {
          int sum = 0;
          for (int i = x; i < x + size; i++) {
              sum += (grid[i][y + size - 1] - grid[i][y - 1]);
          }
  
          if(sum>target) return false;
  
          return sum <= target;
      }
      int maxSideLength(vector<vector<int>>& mat, int threshold) {
          int m = mat.size();
          int n = mat[0].size();
          int minSide = min(m, n);
          int ans = 0;
          vector<vector<int>> pfSum(m + 1, vector<int>(n + 1, 0));
          for (int i = 0; i < m; i++) {
              for (int j = 0; j < n; j++) {
                  pfSum[i + 1][j + 1] = pfSum[i + 1][j] + mat[i][j];
              }
          }
  
          int hi = minSide, lo = 1;
  
          while(hi>=lo){
              int mid = (hi+lo)/2;
              bool good = false;
              for (int j = 1; j + mid <= m + 1; j++) {
                  for (int k = 1; k + mid <= n + 1; k++) {
                      good = isMagicSquare(pfSum, j, k, mid, threshold);
                      if (good) {
                          ans = max(ans, mid);
                          break;
                      }
                  }
                  if (good)
                      break;
              }
              if(good) lo = mid+1;
              else hi = mid-1;
          }
          // for (int i = 0; i <= m; i++) {
          //     for (int j = 0; j <= n; j++) {
          //         cout << pfSum[i][j] << " ";
          //     }
          //     cout << endl;
          // }
  
          return ans;
      }
  };