#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size(), i, j;
        long long result = (n * (n - 1)) / 2;
        unordered_map<int, long long> diff_count;

        for (i = 0; i < n; i++) {
            int temp = nums[i] - i;
            diff_count[temp]++;
        }

        for (auto it : diff_count) {
            if (it.second > 1) {
                long long count = (it.second * (it.second - 1)) / 2;
                result -= count;
            }
        }
        return result;
    }
};