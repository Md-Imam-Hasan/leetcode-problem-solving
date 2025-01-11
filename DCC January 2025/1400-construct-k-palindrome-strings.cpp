#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);
        int i, n = s.length();
        if (n == k)
            return true;
        if(n < k)
            return false;
        for (char ch : s) {
            int idx = ch - 'a';
            freq[idx]++;
        }

        int odd = 0, even = 0;

        for (i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] % 2 == 0)
                even += (freq[i] / 2);
            else if (freq[i] != 0) {
                even += (freq[i] / 2);
                odd++;
            }
        }

        if (odd <= k)
            return true;
        else
            return false;
    }
};