#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0, temp = 0, temp2=0;
        int n = arr.size(), i;

        for(i=0;i<n;i++){
            temp2+=abs(arr[i]-brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for (i = 0; i < n; i++) {
            temp += abs(arr[i] - brr[i]);
        }
        if (temp)
            ans += temp + k;

        return min(ans,temp2);
    }
};