#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        int i;
        
        for(char ch: s){
            int idx = ch - 'a';
            freq[idx]++;
        }
        int ans = 0;

        for(i=0;i<26;i++){
            if(freq[i]%2){
                ans++;
            } else if(freq[i]!=0){
                ans+=2;
            }
        }
        return ans;
    }
};