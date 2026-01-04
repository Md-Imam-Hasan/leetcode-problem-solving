#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        
        // Step 1: Generate all valid patterns for a single row
        // Each cell can be 0, 1, or 2 (representing 3 colors: R, G, B)
        // Adjacent cells must have different colors
        vector<array<int, 3>> p;  // stores all valid row patterns
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;  // adjacent cells can't have same color
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;  // adjacent cells can't have same color
                    p.push_back({i, j, k});
                }
            }
        }

        // print p
        for (int i = 0; i < p.size(); i++) {
            cout << p[i][0] << " " << p[i][1] << " " << p[i][2] << endl;
        }
        // p now has 12 valid patterns: 3 * 2 * 2 = 12
        
        // Step 2: Build adjacency list
        // np[i] contains indices of all patterns that can be placed below pattern p[i]
        // Two patterns are compatible if NO cell has the same color in both rows
        vector<vector<int>> np(p.size());
        for (int i = 0; i < p.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                bool compatible = true;
                for (int k = 0; k < 3; k++) {
                    if (p[i][k] == p[j][k]) {  // same color in same column
                        compatible = false;
                        break;
                    }
                }
                if (compatible) {
                    np[i].push_back(j);  // pattern j can follow pattern i
                }
            }
        }

        // print np
        for (int i = 0; i < np.size(); i++) {
            for (int j = 0; j < np[i].size(); j++) {
                cout << np[i][j] << " ";
            }
            cout << endl;
        }
        
        // Step 3: Dynamic Programming
        // dp[i] = number of ways to reach pattern i in the current row
        vector<long long> dp(p.size(), 1);  // First row: 1 way to use each pattern
        
        for (int row = 1; row < n; row++) {
            vector<long long> new_dp(p.size(), 0);
            for (int i = 0; i < p.size(); i++) {
                for (int j : np[i]) {  // j can follow i
                    new_dp[j] = (new_dp[j] + dp[i]) % MOD;
                }
            }
            dp = new_dp;
        }
        
        // Step 4: Sum all ways to end with any pattern
        long long result = 0;
        for (int i = 0; i < p.size(); i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return (int)result;
    }
};
