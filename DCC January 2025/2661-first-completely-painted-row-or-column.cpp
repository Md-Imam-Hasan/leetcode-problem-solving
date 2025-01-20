#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int len = arr.size(), i, j, m = mat.size(), n = mat[0].size(),
            ans = INT_MAX;
        vector<int> idx(len+1, 0);

        for (i = 0; i < len; i++)
            idx[arr[i]] = i;

        for (i = 0; i < m; i++) {
            int temp = 0;
            for (j = 0; j < n; j++) {
                temp = max(temp, idx[mat[i][j]]);
            }
            ans = min(ans, temp);
        }

        for (j = 0; j < n; j++) {
            int temp = 0;
            for (i = 0; i < m; i++) {
                temp = max(temp, idx[mat[i][j]]);
            }
            ans = min(ans, temp);
        }

        return ans;
    }
};