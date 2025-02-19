#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      string letter_set = "abc";
      void buildString(vector<string>& st, string& temp, int n) {
          if (temp.size() == n) {
              st.push_back(temp);
              return;
          }
          char x = temp[temp.size() - 1];
          for (int i = 0; i < 3; i++) {
              if (letter_set[i] != x) {
                  string res = temp + letter_set[i];
                  buildString(st, res, n);
              }
          }
          return;
      }
  
      string getHappyString(int n, int k) {
          if (3 * round(pow(2, (n - 1))) < k)
              return "";
          vector<string> st;
  
          for (int i = 0; i < 3; i++) {
              string temp = "";
              temp += letter_set[i];
              buildString(st, temp, n);
          }
  
          sort(st.begin(), st.end());
  
          return st[k - 1];
      }
  };