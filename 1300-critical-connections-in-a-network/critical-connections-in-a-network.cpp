class Solution {
private:
    int timer = 1;
private: 
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue; // if adjancent node is parent, dont do anything
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                // once dfs of it completed, it comes back
                low[node] = min(low[node], low[it]);

                // node-----it
                if(low[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else if(vis[it]==1){
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create graph
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};