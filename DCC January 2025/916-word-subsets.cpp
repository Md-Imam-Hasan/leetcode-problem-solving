#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int i, j, n1 = words1.size(), n2 = words2.size();
        vector<string> ans;
        map<char, int> mp;

        for (i = 0; i < n2; i++) {
            map<char, int> temp;
            int len = words2[i].length();
            string s = words2[i];
            for (j = 0; j < len; j++) {
                temp[s[j]]++;
            }
            for (auto k : temp)
                mp[k.first] = max(mp[k.first], k.second);
        }

        for (i = 0; i < n1; i++) {
            bool isSubset = true;
            map<char, int> temp;
            int len = words1[i].length();
            string s = words1[i];
            for (j = 0; j < len; j++) {
                temp[s[j]]++;
            }

            for (auto k : mp)
                if (k.second > temp[k.first]) {
                    isSubset = false;
                    break;
                }

            if (isSubset)
                ans.push_back(words1[i]);
        }

        return ans;
    }
};