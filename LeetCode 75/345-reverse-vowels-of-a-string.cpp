#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size(), i, j, k = 0;
        string vowels = "aeiou";
        string ans = "", temp = "";

        for (i = 0; i < n; i++) {
            for (j = 0; j < 5; j++) {
                char c = s[i];
                if (tolower(c) == vowels[j]) {
                    temp += s[i];
                    break;
                }
            }
        }

        reverse(temp.begin(), temp.end());

        for (i = 0; i < n; i++) {
            for (j = 0; j < 5; j++) {
                char c = s[i];
                if (tolower(c) == vowels[j]) {
                    s[i] = temp[k];
                    k++;
                    break;
                }
            }
        }
        return s;
    }
};