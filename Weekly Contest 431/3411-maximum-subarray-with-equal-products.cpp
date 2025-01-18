#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int len = nums.size(), ans = 0;
        for (int i = 0; i < len; i++) {
            long long currGCD = nums[i], currLCM = nums[i], currPRD = nums[i],
                      maxLCM = 100000000000;
            for (int j = i + 1; j < len; j++) {
                currPRD *= (long long)nums[j];
                if (currPRD > maxLCM)
                    break;
                currGCD = gcd(currGCD, (long long)nums[j]);
                currLCM = lcm(currLCM, (long long)nums[j]);

                if (currPRD == currGCD * currLCM) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};