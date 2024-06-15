#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
  string encode(vector<string> &strs)
  {
    string es = "";
    for (string &s : strs)
    {
      es += s + "/";
    }
    return es;
  }

  vector<string> decode(string s)
  {
    vector<string> ds;

    for (int i = 0; i < s.size(); i++)
    {
      string stopush = "";
      int j;
      for (j = i; j < s.size(); j++)
      {
        if (s[j] == '/')
        {
          ds.push_back(stopush);
          break;
        }
        else
        {
          stopush += s[j];
        }
      }
      i = j;
    }
    return ds;
  }
};
