#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i, ans = 0;

        if (!n1 % 2 && !n2 % 2)
            return 0;
        if (n1 % 2) {
            for (i = 0; i < n2; i++)
                ans ^= nums2[i];
        }
        if (n2 % 2) {
            for (i = 0; i < n1; i++)
                ans ^= nums1[i];
        }

        return ans;
    }
};