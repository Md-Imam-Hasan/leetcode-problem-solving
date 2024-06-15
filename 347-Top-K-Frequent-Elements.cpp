#include <bits/stdc++.h>
#define ll long long
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
const double pi = 2.0 * acos(0.0);
// ok
using namespace std;
class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> mp;

    for (auto &i : nums)
    {
      mp[i]++;
    }

    // Declare vector of pairs
    priority_queue<pair<int, int>> A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : mp)
    {
      A.push({it.second, it.first});
    }

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
      ans.push_back(A.top().second);
      A.pop();
    }

    return ans;
  }
};