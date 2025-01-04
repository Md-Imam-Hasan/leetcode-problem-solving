#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<array<int,2>>vc;
        int cnt=0,i=0, mx=0;
        for(i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                cnt++;
            }
            vc.push_back({cnt,0});
        }
        cnt=0;

        for(i=s.length()-1;i>0;i--){
            if(s[i]=='1'){
                cnt++;
            }
            vc[i-1][1]=cnt;
        }

        for(i=0;i<vc.size();i++){
            mx=max(mx,(vc[i][0]+vc[i][1]));
        }

        return mx;
    }
};