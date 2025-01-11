#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i, n1 = word1.length(), n2 = word2.length();
        int mx = max(n1, n2);
        string ans = "";
        for (i = 0; i < mx; i++) {
            if (i < n1) {
                ans += word1[i];
            }
            if (i < n2) {
                ans += word2[i];
            }
        }
        return ans;
    }
};