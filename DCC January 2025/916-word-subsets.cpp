#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int i;
        vector<string> ans;
        vector<int> maxFreq(26, 0);

        for (const auto& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                int idx = ch - 'a';
                freq[idx]++;
                maxFreq[idx] = max(maxFreq[idx], freq[idx]);
            }
        }

        for (const auto& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                int idx = ch - 'a';
                freq[idx]++;
            }
            bool isSubset = true;
            for (i = 0; i < 26; i++) {
                if (maxFreq[i] > freq[i]) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset)
                ans.push_back(word);
        }

        return ans;
    }
};