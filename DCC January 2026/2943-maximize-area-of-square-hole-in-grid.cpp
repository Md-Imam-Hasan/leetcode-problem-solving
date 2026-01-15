class Solution {
  public:
      int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                                 vector<int>& vBars) {
          sort(hBars.begin(), hBars.end());
          sort(vBars.begin(), vBars.end());
  
          int ans = 0;
          int con1 = 1;
          int con2 = 1;
          int count1 = 1;
          int count2 = 1;
  
          for (int i = 1; i < hBars.size(); i++) {
              if (hBars[i] == hBars[i - 1] + 1) {
                  count1++;
                  con1 = max(con1, count1);
              } else {
                  count1 = 1;
              }
          }
  
          for (int i = 1; i < vBars.size(); i++) {
              if (vBars[i] == vBars[i - 1] + 1) {
                  count2++;
                  con2 = max(con2, count2);
              } else {
                  count2 = 1;
              }
          }
  
          cout<<"con1: "<<con1<<"con2: "<<con2<<endl;
  
          ans = pow((min(con1, con2) + 1), 2);
  
          return ans;
      }
  };