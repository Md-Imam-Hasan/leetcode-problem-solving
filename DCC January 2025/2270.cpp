#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum = 0, rightSum = 0;
        int i,numLen = nums.size(), ans = 0;
        for(i=0;i<numLen;i++){
            sum+=nums[i];
        }

        for(i=0;i<numLen-1;i++){
            rightSum+=nums[i];
            if(rightSum >= sum-rightSum){
                ans++;
            }
        }
        return ans;
    }
};