#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isInsideGrid(int n, int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    int markIsland(vector<vector<int>>& grid, int island_number, int n, int row,
                   int col) {
        grid[row][col] = island_number;
        int count = 1, i;

        for (i = 0; i < 4; i++) {
            int nx = row + dir[i][0];
            int ny = col + dir[i][1];

            if (isInsideGrid(n, nx, ny) && grid[nx][ny] == 1) {
                count += markIsland(grid, island_number, n, nx, ny);
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), i, j, k, island_number = 2, max_island = 0;

        unordered_map<int, int> island_size;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int island = markIsland(grid, island_number, n, i, j);
                    island_size[island_number] = island;
                    island_number++;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    set<int> islands;

                    for (k = 0; k < 4; k++) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (isInsideGrid(n, nx, ny)) {
                            islands.insert(grid[nx][ny]);
                        }
                    }

                    int curr_island = 1;

                    for (auto key : islands) {
                        curr_island += island_size[key];
                    }

                    max_island = max(max_island, curr_island);
                }
            }
        }

        return max_island == 0 ? n * n : max_island;
    }
};