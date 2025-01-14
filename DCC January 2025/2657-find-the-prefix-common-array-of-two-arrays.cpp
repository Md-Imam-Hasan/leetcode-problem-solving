#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, int> mp;
        int i, n = A.size(), temp = 0;
        vector<int> ans;

        for (i = 0; i < n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if (mp[A[i]] == 2)
                temp++;
            if (mp[B[i]] == 2 && A[i] != B[i])
                temp++;
            ans.push_back(temp);
        }
        return ans;
    }
};