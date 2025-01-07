#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> stringMatching(vector<string> &words)
  {
    sort(words.begin(), words.end(),
         [](string &first, string &second)
         {
           return first.size() < second.size();
         });

    int i, j, n = words.size();
    vector<string> ans;

    for (i = 0; i < n - 1; i++)
    {
      for (j = i + 1; j < n; j++)
      {
        if (words[i].length() != words[j].length() &&
            words[j].find(words[i]) != string::npos)
        {
          ans.push_back(words[i]);
          break;
        }
      }
    }
    return ans;
  }
};