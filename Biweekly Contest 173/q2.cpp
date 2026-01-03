class Solution {
  public:
      int minLength(vector<int>& nums, int k) {
          unordered_map<int, int> mp;

          // a sliding window code on nums vector to find the minimum length of the subarray with sum >= k
          int i = 0, j = 0, sum = 0, ans = INT_MAX;
          while(j < nums.size()) {
            mp[nums[j]]++;
            if(mp[nums[j]] == 1) sum += nums[j];
            while(sum >= k) {
                ans = min(ans, j - i + 1);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
      }
  };