#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> ga;
    for (string &s : strs)
    {
      string sortedStr = s;
      sort(sortedStr.begin(), sortedStr.end());
      ga[sortedStr].push_back(s);
    }

    vector<vector<string>> ans;

    for (auto &it : ga)
    {
      ans.push_back(it.second);
    }
    return ans;
  }
};