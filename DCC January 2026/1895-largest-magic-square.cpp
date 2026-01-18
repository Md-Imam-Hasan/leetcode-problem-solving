class Solution {
  public:
      bool isMagicSquare(vector<vector<int>>& grid, int x, int y, int size) {
          vector<int> row(size, 0), col(size, 0);
          int diag = 0, antiDiag = 0;
          for (int i = x; i < x + size; i++) {
              for (int j = y; j < y + size; j++) {
                  row[i - x] += grid[i][j];
                  col[j - y] += grid[i][j];
                  if ((i - x) == (j - y))
                      diag += grid[i][j];
                  if ((i - x) + (j - y) == size - 1)
                      antiDiag += grid[i][j];
              }
          }
          // cout << "x: " << x << " y: " << y << " size: " << size << endl;
          // cout << "diag: " << diag << endl;
          // cout << "antiDiag: " << antiDiag << endl;
          int temp = 0;
          if (diag != antiDiag)
              return false;
          else
              temp = diag;
  
          for (int i = 0; i < size; i++) {
              if (row[i] != temp || col[i] != temp)
                  return false;
          }
          return true;
      }
      int largestMagicSquare(vector<vector<int>>& grid) {
          int m = grid.size();
          int n = grid[0].size();
  
          int minSide = min(m, n);
          int ans = 0;
  
          for (int i = minSide; i >= 1; i--) {
              for (int j = 0; j + i <= m; j++) {
                  for (int k = 0; k + i <= n; k++) {
                      bool good = isMagicSquare(grid, j, k, i);
                      if (good) {
                          ans = max(ans, i);
                      }
                  }
              }
          }
          return ans;
      }
  };