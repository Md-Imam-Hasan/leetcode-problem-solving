#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), i;

        vector<int> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto x : rooms[curr]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};