#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        int n = s.size(), i, j;
        string result = "";

        for (i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                vector<int> freq(10, 0);
                for (char c : s) {
                    if (isdigit(c)) {
                        freq[c - '0']++;
                    }
                }

                int firstNum = s[i] - '0';
                int secondNum = s[i + 1] - '0';
                if (freq[firstNum] == firstNum &&
                    freq[secondNum] == secondNum) {
                    result = s.substr(i, 2);
                    return result;
                }
            }
        }
        return result;
    }
};