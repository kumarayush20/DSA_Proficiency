class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }
    
        vector<int> result;
    
        auto dijkstra = [&](int start, int end) -> int {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[start] = 0;
            pq.push({0, start});
        
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
            
                if (d > dist[u]) continue;
            
                for (int v : adj[u]) {
                    if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                        pq.push({dist[v], v});
                    }
                }
            }
        
            return dist[end];
        };
    
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            result.push_back(dijkstra(0, n - 1));
        }
    
        return result;
    }
};