#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        
        vector<int> diff_indices;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff_indices.push_back(i);
            }
            if (diff_indices.size() > 2) return false;
        }
        
        if (diff_indices.size() == 0) return true;
        if (diff_indices.size() == 1) return false;
        
        int i = diff_indices[0];
        int j = diff_indices[1];
        
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};