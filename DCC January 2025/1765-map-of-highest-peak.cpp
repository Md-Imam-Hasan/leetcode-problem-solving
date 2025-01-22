#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
#define pip pair<int, pair<int, int>>
    bool isInsideGrid(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), i, j;
        priority_queue<pip, vector<pip>, greater<pip>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    pq.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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
                    pq.push({height + 1, {nx, ny}});
                    ans[nx][ny] = height + 1;
                }
            }
        }

        return ans;
    }
};