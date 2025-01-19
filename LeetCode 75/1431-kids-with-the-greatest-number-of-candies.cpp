#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), i, mx = 0;
        vector<bool> ans(n, false);

        for (i = 0; i < n; i++) {
            mx = max(candies[i], mx);
        }

        for (i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= mx)
                ans[i] = true;
        }

        return ans;
    }
};