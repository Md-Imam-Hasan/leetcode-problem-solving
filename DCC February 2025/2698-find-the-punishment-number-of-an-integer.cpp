#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      bool isValid(string sq, int pos, int sum, int val) {
          if (pos >= sq.size()) {
              return sum == val;
          }
  
          for (int i = 0; i + pos < sq.size(); i++) {
              int curr_value = stoi(sq.substr(pos, i + 1));
              if (isValid(sq, i + pos + 1, sum + curr_value, val)) {
                  return true;
              }
          }
          return false;
      }
      int punishmentNumber(int n) {
          int result = 1, i;
  
          for (i = 2; i <= n; i++) {
              string sq = to_string(i * i);
              if (isValid(sq, 0, 0, i)) {
                  result += i * i;
              }
          }
          return result;
      }
  };