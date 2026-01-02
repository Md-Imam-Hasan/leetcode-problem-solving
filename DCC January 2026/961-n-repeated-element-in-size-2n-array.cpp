class Solution {
  public:
      int repeatedNTimes(vector<int>& nums) {
          unordered_map<int, bool> mp;
          int ans;
  
          for (int x: nums) {
              if (mp[x]) {
                  ans = x;
              } else {
                  mp[x]=true;
              }
          }
          return ans;
      }
  };