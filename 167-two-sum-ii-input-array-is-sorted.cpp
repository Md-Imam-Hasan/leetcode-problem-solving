#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  static int binarysearch(vector<int> &arr, int low, int high, int x)
  {
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] == x)
        return mid;
      if (arr[mid] < x)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return -1;
  }
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int> ans;
    int nsize = numbers.size() - 1, nf, j;
    for (int i = 0; i < nsize; i++)
    {
      nf = target - numbers[i];
      j = binarysearch(numbers, i + 1, nsize, nf);
      if (j >= 0 && j != i)
      {
        ans.push_back(i+1);
        ans.push_back(j+1);
        break;
      }
    }

    return ans;
  }
};