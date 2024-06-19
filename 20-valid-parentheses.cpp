#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    vector<char> result;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '[' || s[i] == '{' || s[i] == '(')
      {
        result.push_back(s[i]);
      }
      else if (s[i] == ']' && result.size() > 0 && result.back() == '[')
      {
        result.pop_back();
      }
      else if (s[i] == '}' && result.size() > 0 && result.back() == '{')
      {
        result.pop_back();
      }
      else if (s[i] == ')' && result.size() > 0 && result.back() == '(')
      {
        result.pop_back();
      }
      else
      {
        return false;
      }
    }

    if (result.size() > 0)
      return false;
    return true;
  }
};
