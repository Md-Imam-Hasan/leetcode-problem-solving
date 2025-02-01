#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& arr, int n, int k)
    {
        if (n < k) {
            return -1;
        }
        queue<int> q;
    
        int m = 0;
        int su = 0;
    
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
            su += arr[i];
        }
    
        for (int i = k; i < n; i++) {
              m = max(m, su);
            su -= q.front();
            q.pop();
            q.push(arr[i]);
            su += arr[i];
        }
        m = max(m, su);
        return m;
    }
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), i, j;
        vector<int> arr;
        arr.push_back(abs(0-startTime[0]));

        for(i=0;i<n-1;i++){
            arr.push_back(abs(endTime[i]-startTime[i+1]));
        }
        arr.push_back(abs(endTime[i]-eventTime));

        int arr_size = arr.size();

        return maxSum(arr, arr_size, k+1);
    }
};