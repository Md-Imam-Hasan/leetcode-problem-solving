#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInsideGrid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, ans = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        deque<pair<int, int>> q;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    q.push_back({i, j});
                    visited[i][j] = true;
                    int count = 0;
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop_front();
                        count++;
                        int x = p.first, y = p.second;
                        for (int k = 0; k < m; k++) {
                            if (grid[k][y] == 1 && !visited[k][y]) {
                                q.push_back({k, y});
                                visited[k][y] = true;
                            }
                        }
                        for (int k = 0; k < n; k++) {
                            if (grid[x][k] == 1 && !visited[x][k]) {
                                q.push_back({x, k});
                                visited[x][k] = true;
                            }
                        }
                    }
                    if (count > 1) ans += count;
                }
            }
        }

        return ans;
    }
};