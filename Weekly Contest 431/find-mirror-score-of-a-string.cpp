#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char mirrorLetter(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return 'z' - (ch - 'a');
        }
        return ch;
    }
    long long calculateScore(string s) {
        int i, len = s.length();
        long long ans = 0;
        vector<bool> vc(len, false);
        map<char, deque<int>> mp;

        for (i = 0; i < len; i++) {
            if (vc[i]) continue;

            if (!mp[s[i]].empty()) {
                int x = mp[s[i]].back();
                mp[s[i]].pop_back();
                vc[i] = true;
                vc[x] = true;
                ans += (i - x);
            } else {
                mp[mirrorLetter(s[i])].push_back(i);
            }
        }

        return ans;
    }
};