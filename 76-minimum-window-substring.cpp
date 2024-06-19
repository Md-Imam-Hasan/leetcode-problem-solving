#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    if ((s.length() == t.length() && s != t) || s.length() < t.length())
    {
      return "";
    }
    int start = 0, end = 0, minL = INT_MAX, startIndex;
    vector<int> mp(128, 0);
    int count = t.length();

    for (auto c : t)
    {
      mp[c]++;
    }

    while (end < s.length())
    {
      if (mp[s[end++]]-- > 0)
      {
        count--;
      }

      while (count == 0)
      {
        if (end - start < minL)
        {
          minL = end - start;
          startIndex = start;
        }
        if (mp[s[start++]]++ == 0)
        {
          count++;
        }
      }
    }

    return minL == INT_MAX ? "" : s.substr(startIndex, minL);
  }
};