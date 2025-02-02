#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i, j, x = 0;

        for (i = 0, j = 0; i < n; i++) {
            if (nums[i] == 0)
                x++;
            else if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        for (i = n - 1; i >= 0 && x > 0; i--, x--) {
            nums[i] = 0;
        }
    }
};