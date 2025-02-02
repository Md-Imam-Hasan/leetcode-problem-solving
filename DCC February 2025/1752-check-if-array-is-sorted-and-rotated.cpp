#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), i, j;
        vector<int> left, right;
        bool temp = false;
        left.push_back(nums[0]);

        for (i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1] && !temp) {
                left.push_back(nums[i]);
            }
            if (nums[i] >= nums[i - 1] && temp) {
                right.push_back(nums[i]);
            }
            if (nums[i] < nums[i - 1]) {
                temp = true;
                right.push_back(nums[i]);
            }
        }

        right.insert(right.end(), left.begin(), left.end());

        sort(nums.begin(), nums.end());

        for (i = 0; i < n; i++) {
            if (nums[i] != right[i]) {
                return false;
            }
        }

        return true;
    }
};