#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0, l = 0, r = 0;
        if (s.length() <= 1)
        {
            return s.length();
        }
        unordered_map<char, int> mp;

        while (r < s.length())
        {
            if (mp.count(s[r]) == 0 || mp[s[r]] < l)
            {
                result = max(result, r - l + 1);
            }
            else
            {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            r++;
        }

        return result;
    }
};