#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void DFSRec(vector<vector<int>>& adj, vector<bool>& visited, int s) {
        visited[s] = true;
        for (int i : adj[s])
            if (visited[i] == false)
                DFSRec(adj, visited, i);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), i, j;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;

        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                DFSRec(adj, visited, i);
                result++;
            }
        }

        return result;
    }
};