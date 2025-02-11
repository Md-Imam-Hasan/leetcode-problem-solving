#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      string removeSubstring(string& s1, string& s2) {
          size_t pos = s2.find(s1);
  
          if (pos != std::string::npos) {
              s2.erase(pos, s1.length());
              return removeSubstring(s1, s2);
          } else {
              return s2;
          }
      }
      string removeOccurrences(string s, string part) {
          int n = s.size(), m = part.size(), i, j;
          string ans = "";
  
          if (m > n)
              return s;
          else if (s == part)
              return "";
  
          return removeSubstring(part, s);
      }
  };