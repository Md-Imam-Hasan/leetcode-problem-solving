#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int ans = 0, i;

    for (i = 0; i < nums.size() - 2; i++)
    {
      if (nums[i] == 0)
      {
        ans += 1;
        nums[i] = !nums[i];
        nums[i + 1] = !nums[i + 1];
        nums[i + 2] = !nums[i + 2];
      }
    }
    if (nums[i] && nums[i + 1])
    {
      return ans;
    }

    return -1;
  }
};