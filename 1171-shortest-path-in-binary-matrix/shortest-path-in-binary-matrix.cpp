class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 && grid.size()==1) return 1;

        int n = grid.size();
        pair<int, int> destination = {n-1, n-1};
        pair<int, int> src = {0,0};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 0;
        q.push({1, {0,0}});

        vector<int> dr = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dc = {1, -1, 0, 0, 1, -1, 1, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int col = it.second.second;
            int row = it.second.first;

            for(int i=0; i<8; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;

                    if(nrow == n-1 && ncol == n-1){
                        return dis + 1;
                    }
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};