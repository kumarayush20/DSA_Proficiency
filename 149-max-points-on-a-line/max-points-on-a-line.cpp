class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 1;

        int result = 0;
        for(int i=0; i<n; i++){
            unordered_map<double, int> mpp;
            for(int j=0; j<n; j++){
                if(i==j) continue;

                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];

                auto theta = atan2(dy, dx);

                mpp[theta]++;
            }
            for(auto &it : mpp){
                result = max(result, it.second + 1);
            }
        }
        return result;
    }
};