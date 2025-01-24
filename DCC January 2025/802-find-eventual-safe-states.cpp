#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> safe_nodes;
    bool checkSafeNode(vector<vector<int>>& graph, vector<int>& visited,
                       int curr) {
        visited[curr] = 1;
        bool is_safe = true;

        for (auto nbr : graph[curr]) {
            if (visited[nbr] == 0)
                is_safe &= checkSafeNode(graph, visited, nbr);
            else if (visited[nbr] == 1)
                return safe_nodes[curr] = false;
            else if (visited[nbr] == 2)
                is_safe &= safe_nodes[nbr];
        }
        visited[curr] = 2;
        return safe_nodes[curr] = is_safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(), i;
        safe_nodes = vector<bool>(n, true);

        vector<int> visited(n, 0);

        for (i = 0; i < n; i++) {
            if (visited[i] == 0) {
                checkSafeNode(graph, visited, i);
            }
        }

        vector<int> ans;

        for (i = 0; i < n; i++) {
            if (safe_nodes[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};