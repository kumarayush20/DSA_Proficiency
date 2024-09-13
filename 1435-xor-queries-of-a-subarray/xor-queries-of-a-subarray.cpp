class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        for(int i=0; i<n; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int num = 0;
            for(int j=left; j<=right; j++){
                num = num ^ arr[j];
            }
            ans.push_back(num);
        }

        return ans;
    }
};