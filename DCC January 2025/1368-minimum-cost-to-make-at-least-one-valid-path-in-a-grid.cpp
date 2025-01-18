#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInsideGrid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        cost[0][0] = 0;
        q.push_back({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();

            int nextDir = grid[i][j] - 1;

            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k].first;
                int nj = j + dir[k].second;

                if (isInsideGrid(m, n, ni, nj)) {
                    int weight = (k == nextDir) ? 0 : 1;
                    int newCost = cost[i][j] + weight;

                    if (newCost < cost[ni][nj]) {
                        cost[ni][nj] = newCost;
                        if (weight == 0) {
                            q.push_front({ni, nj});
                        } else {
                            q.push_back({ni, nj});
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};