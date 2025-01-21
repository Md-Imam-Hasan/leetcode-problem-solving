#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size(), i;
        long long firstRowSum = 0, secondRowSum = 0, minimumSum = LONG_LONG_MAX;

        for (i = 0; i < n; i++) {
            firstRowSum+=grid[0][i];
        }

        for(i=0;i<n;i++){
            firstRowSum-=grid[0][i];
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum+=grid[1][i];
        }

        return minimumSum;
    }
};