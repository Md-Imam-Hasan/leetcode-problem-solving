#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), i, j = 0;
        bool ans = true;

        for (i = 0; i < n; i++) {
            bool temp = false;
            for (; j < m; j++) {
                if (s[i] == t[j]) {
                    temp = true;
                    j++;
                    break;
                }
            }
            if (!temp)
                ans = false;
        }
        return ans;
    }
};