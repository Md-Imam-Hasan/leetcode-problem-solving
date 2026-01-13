class Solution {
  public:
      bool canculatedArea(double mid, double totalArea,
                          vector<vector<int>>& squares) {
          double area = 0;
  
          for (int i = 0; i < squares.size(); i++) {
              int y = squares[i][1], l = squares[i][2];
              if (y < mid) {
                  area += min(mid - y, (double)l) * l;
              }
          }
  
          return area >= totalArea / 2;
      }
      double separateSquares(vector<vector<int>>& squares) {
          double maxY = INT_MIN;
          double totalArea = 0;
          for (int i = 0; i < squares.size(); i++) {
              int y = squares[i][1], l = squares[i][2];
              totalArea += (double)l * l;
              maxY = max(maxY, (double)(y + l));
          }
  
          double l = 0, r = maxY;
          cout << "l: " << l << "r: " << r << endl;
  
          double eps = 1e-5;
  
          while (abs(r - l) > eps) {
              double mid = (l + r) / 2;
              bool good = canculatedArea(mid, totalArea, squares);
              if (good) {
                  r = mid;
              } else {
                  l = mid;
              }
          }
  
          return r;
      }
  };