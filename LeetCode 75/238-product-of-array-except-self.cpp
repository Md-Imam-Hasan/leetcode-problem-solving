#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),i,x=1,y=1;
        vector<int>fromBegin(n,1), fromEnd(n,1), ans(n,1);

        for(i=0;i<n;i++){
            if(i==0){
                fromBegin[i] = nums[i];
            } else {
                fromBegin[i] = fromBegin[i-1]*nums[i];
            }
        }

        for(i=n-1;i>=0;i--){
            if(i==n-1){
                fromEnd[i] = nums[i];
            } else {
                fromEnd[i] = fromEnd[i+1]*nums[i];
            }
        }

        for(i=0;i<n;i++){
            x=1,y=1;
            if(i>0){
                x=fromBegin[i-1];
            }
            if(i<n-1){
                y=fromEnd[i+1];
            }
            ans[i] = x*y;
        }

        return ans;
    }
};