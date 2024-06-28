#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int left = 1, right = *max_element(piles.begin(), piles.end()), mid;
    int res = right;

    while (left <= right)
    {
      long int k = 0;
      mid = (left + right) / 2;

      for (int i = 0; i < piles.size(); i++)
      {
        k += ceil((double)piles[i] / mid);
      }
      if (k <= h)
      {
        res = min(res, mid);
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return res;
  }
};