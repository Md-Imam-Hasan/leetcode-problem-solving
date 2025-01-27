#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int s, int d) {
        queue<int> q;
        vector<bool> visited(adj.size(), false);
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int x : adj[curr]) {
                if (x == d)
                    return true;
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        int n = prerequisites.size(), m = queries.size(), i, j;
        vector<vector<int>> adj(numCourses);

        for (i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> ans;

        for (i = 0; i < m; i++) {
            int s = queries[i][0], d = queries[i][1];
            bool temp = bfs(adj, s, d);
            ans.push_back(temp);
        }

        return ans;
    }
};