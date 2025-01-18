#include <bits/stdc++.h>

using namespace std;

// TODO: Not solved yet

class Solution {
public:
    vector<int> getOrder(const vector<int>& brr) {
        vector<int> indices(brr.size());
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(),
             [&](int i1, int i2) { return brr[i1] < brr[i2]; });

        return indices;
    }

    void sortByBrr(vector<int>& arr, const vector<int>& brr) {
        vector<int> sorted_indices = getOrder(brr);
        vector<int> temp(arr.size());

        sort(arr.begin(), arr.end());

        for (size_t i = 0; i < arr.size(); ++i) {
            temp[i] = arr[sorted_indices[i]];
        }

        arr = move(temp);
    }
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0, temp = 0, temp2=0;
        int n = arr.size(), i;

        for(i=0;i<n;i++){
            temp2+=abs(arr[i]-brr[i]);
        }

        sortByBrr(arr, brr);

        for(i=0;i<n;i++) cout<<arr[i]<<"\n";

        for (i = 0; i < n; i++) {
            temp += abs(arr[i] - brr[i]);
        }
        if (temp)
            ans += temp + k;

        return min(ans,temp2);
    }
};