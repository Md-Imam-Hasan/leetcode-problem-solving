#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMultiple(string& s1, string& s2) {
        string testStr = "";
        int repeatCount = s1.length() / s2.length();
        for (int i = 0; i < repeatCount; ++i) {
            testStr += s2;
        }

        return testStr == s1;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int c = gcd(n1, n2);

        string temp = str1.substr(0, c);
        if (isMultiple(str1, temp) && isMultiple(str2, temp))
            return temp;
        else
            return "";
    }
};