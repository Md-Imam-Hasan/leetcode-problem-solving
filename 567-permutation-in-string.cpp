#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s1.length() > s2.length())
      return false;
    vector<int> fs1(26, 0), fs2(26, 0);
    int l = 0, r = s1.length();

    for (int i = 0; i < s1.length(); i++)
    {
      if (fs1[s1[i] - 97] == 0)
        fs1[s1[i] - 97] = 1;
      else
        fs1[s1[i] - 97]++;
    }

    for (int i = l; i < r; i++)
    {
      if (fs2[s2[i] - 97] == 0)
        fs2[s2[i] - 97] = 1;
      else
        fs2[s2[i] - 97]++;
    }

    while (r < s2.length())
    {
      if (fs1 == fs2)
      {
        return true;
      }
      else
      {
        fs2[s2[l] - 97]--;
        l++;
        fs2[s2[r] - 97]++;
        r++;
      }
    }
    if (fs1 == fs2)
    {
      return true;
    }

    return false;
  }
};