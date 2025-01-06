#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i, n = boxes.length();
        vector<int>ans(n,0);

        int prefCount = 0, prefSum = 0;

        for(i=0;i<n;i++){
            ans[i] = prefCount*i - prefSum;
            if(boxes[i]=='1'){
                prefCount++;
                prefSum+=i;
            }
        }

        int sufCount = 0, sufSum = 0;

        for(i=n-1;i>=0;i--){
            ans[i]+=sufSum - sufCount*i;
            if(boxes[i]=='1'){
                sufCount++;
                sufSum+=i;
            }
        }

        return ans;
    }
};