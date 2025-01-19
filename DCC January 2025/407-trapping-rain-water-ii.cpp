#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
#define pip pair<int, pair<int, int>>
    bool isInsideGrid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), i, j;

        priority_queue<pip, vector<pip>, greater<pip>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;

        while (!pq.empty()) {
            int height = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (isInsideGrid(m, n, nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (heightMap[nx][ny] < height) {
                        ans += height - heightMap[nx][ny];
                    }
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return ans;
    }
};