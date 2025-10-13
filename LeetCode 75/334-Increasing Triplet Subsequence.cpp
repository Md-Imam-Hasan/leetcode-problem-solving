class Solution
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    int n = INT_MAX, m = INT_MAX;
    for (int x : nums)
    {
      if (x <= n)
        n = x;
      else if (x > n && x <= m)
        m = x;
      else if (x > m)
        return true;
    }
    return false;
  }
};