#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isInsideGrid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int m,
            int n, int row, int col) {
        visited[row][col] = true;
        int result = grid[row][col], i;

        for (i = 0; i < 4; i++) {
            int nx = row + dir[i][0];
            int ny = col + dir[i][1];

            if (isInsideGrid(m, n, nx, ny) && !visited[nx][ny] &&
                grid[nx][ny] > 0) {
                result += dfs(grid, visited, m, n, nx, ny);
            }
        }
        return result;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, ans = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, visited, m, n, i, j));
                }
            }
        }

        return ans;
    }
};