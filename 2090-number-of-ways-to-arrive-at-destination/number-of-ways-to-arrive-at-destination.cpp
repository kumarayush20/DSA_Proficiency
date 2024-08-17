class Solution {
    typedef long long ll;
    typedef pair<long long, long long> pll;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0,0});

        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll edgeW = it.second;
                
                // 1st time coming
                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    pq.push({dis+edgeW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edgeW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }              
            }
        }
        return ways[n-1] % mod;
    }
};