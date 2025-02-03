#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), inc = 0, dec = 0, r = 0, l = 1;

        if (n == 1)
            return 1;

        while (l < n) {
            if (nums[l] <= nums[l - 1]) {
                r = l;
            }
            inc = max(inc, l - r + 1);
            l++;
        }
        r = 0, l = 1;

        while (l < n) {
            if (nums[l] >= nums[l - 1]) {
                r = l;
            }
            dec = max(dec, l - r + 1);
            l++;
        }

        return max(inc, dec);
    }
};