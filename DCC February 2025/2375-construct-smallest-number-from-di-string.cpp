#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      string smallestNumber(string pattern) {
          int n = pattern.size(), i = 0;
          stack<int> stack;
          string result = "";
  
          do {
              i++;
              stack.push(i);
              if (pattern[i - 1] == 'I') {
                  while (!stack.empty()) {
                      int x = stack.top();
                      result += to_string(x);
                      stack.pop();
                  }
              }
  
          } while (i <= n);
          while (!stack.empty()) {
              int x = stack.top();
              result += to_string(x);
              stack.pop();
          }
  
          return result;
      }
  };