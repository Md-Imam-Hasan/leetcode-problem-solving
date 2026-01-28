#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Find max value in grid
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        
        // cost[i][j] = minimum cost to reach destination from (i, j)
        vector<vector<long long>> cost(n, vector<long long>(m, LLONG_MAX));
        cost[n-1][m-1] = 0;
        
        vector<long long> tcost(maxVal + 1, LLONG_MAX);
        
        for (int t = 0; t <= k; t++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    // move right, down, or teleport
                    if (i < n - 1 && cost[i+1][j] != LLONG_MAX) {
                        cost[i][j] = min(cost[i][j], cost[i+1][j] + grid[i+1][j]);
                    }
                    if (j < m - 1 && cost[i][j+1] != LLONG_MAX) {
                        cost[i][j] = min(cost[i][j], cost[i][j+1] + grid[i][j+1]);
                    }
                    if (t > 0) {
                        cost[i][j] = min(cost[i][j], tcost[grid[i][j]]);
                    }
                }
            }
            
            // compute tcost for next t
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    tcost[grid[i][j]] = min(tcost[grid[i][j]], cost[i][j]);
                }
            }
            // compute prefix min
            for (int i = 1; i <= maxVal; i++) {
                tcost[i] = min(tcost[i], tcost[i-1]);
            }
        }
        
        return (int)cost[0][0];
    }
};

// time: O(k * (nm + M))
// space: O(nm + M)