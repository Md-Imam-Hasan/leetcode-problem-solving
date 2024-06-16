#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int left = 0, right = height.size() - 1, mx_water = 0;

    while (left < right)
    {
      int side = min(height[left], height[right]);
      int d = right - left;
      // cout << d << " " << side << " \n";
      mx_water = max(side * d, mx_water);

      if (side == height[left])
        left++;
      else
        right--;
    }
    return mx_water;
  }
};