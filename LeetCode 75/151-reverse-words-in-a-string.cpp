#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i;
        vector<string> result;

        for (i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;
            else {
                string temp = "";
                for (; i < n; i++) {
                    if (s[i] == ' ')
                        break;
                    else
                        temp += s[i];
                }
                result.push_back(temp);
            }
        }
        string ans = "";
        for (i = result.size() - 1; i >= 0; i--) {
            ans += result[i];
            if(i!=0) ans+=' ';
        }
        return ans;
    }
};