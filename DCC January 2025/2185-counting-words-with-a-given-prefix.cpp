#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, i, n= words.size();
        for(i=0;i<n;i++){
            if(words[i].starts_with(pref)){
                ans++;
            }
        }

        return ans;
    }
};