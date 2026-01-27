#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> radj(n);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            radj[v].push_back({u, w});
        }
        
        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [cost, u, sw] = pq.top();
            pq.pop();
            
            if (cost > dist[u][sw]) continue;
            
            if (u == n - 1) return (int)cost;
            
            for (auto& [v, w] : adj[u]) {
                long long nc = cost + w;
                if (nc < dist[v][1]) {
                    dist[v][1] = nc;
                    pq.push({nc, v, 1});
                }
            }

            if (sw == 1) {
                for (auto& [src, w] : radj[u]) {
                    long long nc = cost + 2LL * w;
                    if (nc < dist[src][1]) {
                        dist[src][1] = nc;
                        pq.push({nc, src, 1});
                    }
                }
                if (cost < dist[u][0]) {
                    dist[u][0] = cost;
                    pq.push({cost, u, 0});
                }
            }
        }
        
        return -1;
    }
};