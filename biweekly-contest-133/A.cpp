#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minimumOperations(vector<int> &nums)
  {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] % 3 != 0)
      {
        ans += 1;
      }
    }

    return ans;
  }
};