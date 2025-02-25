#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int numOfSubarrays(vector<int> &arr)
  {
    int MOD = 1000000007, odd_count = 0, even_count = 1, total = 0, prefix_sum = 0;

    for (int ele : arr)
    {
      prefix_sum += ele;
      if (prefix_sum & 1)
      {
        total = (total + even_count) % MOD;
        odd_count++;
      }
      else
      {
        total = (total + odd_count) % MOD;
        even_count++;
      }
    }
    return total;
  }
};