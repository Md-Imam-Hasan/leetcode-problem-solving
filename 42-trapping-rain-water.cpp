#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int result = 0, l = 0, r = height.size() - 1, maxL = 0, maxR = 0;

    while (l < r)
    {
      if (height[l] <= height[r])
      {
        if (maxL > height[l])
        {
          result += maxL - height[l];
        }
        else
        {
          maxL = height[l];
        }
        l++;
      }
      else
      {
        if (maxR > height[r])
        {
          result += maxR - height[r];
        }
        else
        {
          maxR = height[r];
        }
        r--;
      }
    }

    return result;
  }
};