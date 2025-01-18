#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), i, ans = 0;

        for (i = 0; i < n - 1; i++) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }
        ans = max(ans, abs(nums[0] - nums[n - 1]));

        return ans;
    }
};