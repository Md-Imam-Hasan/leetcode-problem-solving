#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      string clearDigits(string s) {
          int n = s.size(), i;
          string result = "";
  
          for (i = 0; i < n; i++) {
              if (s[i] >= 'a' && s[i] <= 'z') {
                  result += s[i];
              } else {
                  result = result.substr(0, result.size() - 1);
              }
          }
  
          return result;
      }
  };