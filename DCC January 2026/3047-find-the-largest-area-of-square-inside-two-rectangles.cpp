class Solution {
  public:
      long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                  vector<vector<int>>& topRight) {
          int n = bottomLeft.size();
          long long ans = 0;
  
          for (int i = 0; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  int ax = bottomLeft[i][0];
                  int ay = bottomLeft[i][1];
                  int bx = topRight[i][0];
                  int by = topRight[i][1];
                  int cx = bottomLeft[j][0];
                  int cy = bottomLeft[j][1];
                  int dx = topRight[j][0];
                  int dy = topRight[j][1];
  
                  int overlapx = max((min(bx, dx) - max(ax, cx)), 0);
                  int overlapy = max((min(by, dy) - max(ay, cy)), 0);
  
                  long long area = pow(min(overlapx, overlapy), 2);
                  ans = max(area, ans);
              }
          }
  
          return ans;
      }
  };