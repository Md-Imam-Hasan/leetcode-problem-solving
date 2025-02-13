#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      #define ll long long
      int minOperations(vector<int>& nums, int k) {
          int n = nums.size(), ans = 0;
          priority_queue<ll, vector<ll>, greater<ll> > pq(
          nums.begin(), nums.end());
          
          while (true) {
              ll x = pq.top();
              pq.pop();
              ll y = pq.top();
              pq.pop();
  
              if (x < k || y < k) {
                  long long z = min(x, y) * 2 + max(x, y);
                  pq.push(z);
                  ans++;
                  if (pq.size() == 1)
                      break;
              } else
                  break;
          }
          return ans;
      }
  };