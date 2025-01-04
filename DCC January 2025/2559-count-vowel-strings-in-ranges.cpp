#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int i, j, cnt = 0;
        string vl = "aeiou", s;
        vector<int> stv, ans;
        
        for (i = 0; i < words.size(); i++) {
            s = words[i];
            if (vl.find(s[0]) != string::npos && vl.find(s.back()) != string::npos) {
                cnt++;
            } 
            stv.push_back(cnt);
        }

        for (i = 0; i < queries.size(); i++) {
            int lower = queries[i][0], upper = queries[i][1];
            int x = stv[upper];
            if (lower > 0) {
                x -= stv[lower - 1];
            }
            ans.push_back(x);
        }
        return ans;
    }
};
