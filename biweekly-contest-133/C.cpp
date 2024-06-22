#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int ans = 0, i;

    for (i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0 && ans % 2 == 0)
      {
        ans += 1;
      }
      else if (nums[i] == 1 && ans % 2 != 0)
      {
        ans += 1;
      }
    }

    return ans;
  }
};