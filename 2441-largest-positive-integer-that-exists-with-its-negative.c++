#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int findMaxK(vector<int> &v)
  {
    sort(v.begin(), v.end());

    int i = 0, j = v.size() - 1;
    while (i < j)
    {
      if (v[i] == -1 * v[j])
      {
        return v[j];
      }
      else if (-1 * v[i] < v[j])
      {
        j--;
      }
      else if (-1 * v[i] > v[j])
      {
        i++;
      }
    }

    return -1;
  }
};