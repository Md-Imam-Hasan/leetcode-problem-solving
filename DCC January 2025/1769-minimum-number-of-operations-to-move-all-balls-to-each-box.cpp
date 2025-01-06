#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i, j, len = boxes.length(), temp;
        vector<int>ans;

        for(i=0;i<len;i++){
            temp=0;
            for(j=0;j<len;j++){
                if(j==i) continue;
                if(boxes[j]=='1'){
                    temp+=abs(j-i);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};