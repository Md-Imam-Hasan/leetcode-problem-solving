#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {        
        vector<long long> upper(n, INT_MAX);
        upper[0] = 0;
        
        for (auto& r : restrictions) {
            int idx = r[0];
            int maxVal = r[1];
            upper[idx] = min(upper[idx], maxVal);
        }
        
        for (int i = 1; i < n; i++) {
            upper[i] = min(upper[i], upper[i-1] + diff[i-1]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            upper[i] = min(upper[i], upper[i+1] + diff[i]);
        }
        
        return (int)*max_element(upper.begin(), upper.end());
    }
};