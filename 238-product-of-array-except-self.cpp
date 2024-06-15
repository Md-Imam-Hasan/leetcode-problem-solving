#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int nsize = nums.size();
    vector<int> ans(nsize, 1);
    int prefP = 1;
    for (int i = 0; i < nsize; i++)
    {
      ans[i] = prefP;
      prefP *= nums[i];
    }
    int suffP = 1;
    for (int i = nsize - 1; i >= 0; i--)
    {
      ans[i] *= suffP;
      suffP *= nums[i];
    }
    return ans;
  }
};