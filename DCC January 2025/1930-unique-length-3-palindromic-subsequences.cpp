#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, i, j, first, last;

        for(i=0;i<26;i++){
            first = s.find(i+'a');
            last = s.find_last_of(i+'a');

            if(first != string::npos && last != string::npos){
                if(last>first+1){
                    map<char, int> count;
                    for(j=first+1;j<last;j++){
                        count[s[j]]++;
                    }
                    ans+=count.size();
                }
            }
        }
        return ans;
    }
};