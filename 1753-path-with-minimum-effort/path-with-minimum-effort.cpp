class Solution {
    typedef pair<int, pair<int, int>> P;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue <P, vector<P>, greater<P>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row==n-1 && col==m-1) return diff;

            for(int i=0; i<4; i++){
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};