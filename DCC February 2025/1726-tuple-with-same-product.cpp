#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), i, j, ans = 0;
        unordered_map<int,int> product;

        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                int temp = nums[i]*nums[j];
                product[temp]++;
            }
        }

        for(auto it:product){
            if(it.second>1){
                ans+=(nCr(it.second, 2)*8);
            }
        }

        return ans;
    }
};