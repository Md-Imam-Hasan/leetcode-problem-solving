#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int left = 0, right = 0, ans = 0, maxF = 0;
    unordered_map<char, int> mp;

    while (right < s.length())
    {
      mp[s[right]]++;
      maxF = max(maxF, mp[s[right]]);

      if ((right - left + 1) - maxF > k)
      {
        mp[s[left]]--;
        maxF = max(maxF, mp[s[left]]);
        left++;
      }
      else
      {
        ans = max(ans, right - left + 1);
      }
      right++;
    }

    return ans;
  }
};