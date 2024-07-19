class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rMinMax = INT_MIN;
        for(int i=0; i<n; i++){
            int rMin = INT_MAX;
            for(int j=0; j<m; j++){
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        }

        int cMaxMin = INT_MAX;
        for(int i=0; i<m; i++){
            int cMax = INT_MIN;
            for(int j=0; j<n; j++){
                cMax = max(cMax, matrix[j][i]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }

        if(rMinMax == cMaxMin){
            return {rMinMax};
        }

        return {};
    }
};