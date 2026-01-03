#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      string reversePrefix(string s, int k) {
          reverse(s.begin(), s.begin() + k);
          return s;
      }
  };

int main() {
    Solution obj;
    string s = "abcdefg";
    int k = 2;
    cout << obj.reversePrefix(s, k) << endl;
    return 0;
}