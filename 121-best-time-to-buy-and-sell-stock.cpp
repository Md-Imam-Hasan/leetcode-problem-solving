#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int result = 0, x = prices.size(), l = 0, r = 1;

    while (r < x)
    {
      if (prices[r] >= prices[l])
      {
        result = max((prices[r] - prices[l]), result);
      }
      else
      {
        l = r;
      }
      r++;
    }

    return result;
  }
};