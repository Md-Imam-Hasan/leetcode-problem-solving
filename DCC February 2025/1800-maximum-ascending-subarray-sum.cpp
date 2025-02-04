#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = 0, l = 1, temp = 0;

        if (n == 1)
            return nums[0];

        temp = nums[0];
        sum = max(sum, temp);

        while (l < n) {
            if (nums[l] > nums[l - 1]) {
                temp += nums[l];
            } else {
                temp = nums[l];
            }
            sum = max(sum, temp);
            l++;
        }

        return sum;
    }
};