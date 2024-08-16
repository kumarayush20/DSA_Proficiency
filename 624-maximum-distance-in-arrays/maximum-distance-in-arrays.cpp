class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int global_min = arrays[0][0];
        int global_max = arrays[0].back();
        int max_diff = 0;
        
        for (int i = 1; i < n; i++) {
            int curr_min = arrays[i][0];
            int curr_max = arrays[i].back();

            // Calculate max difference using the current array's minimum and the global maximum
            max_diff = max(max_diff, abs(curr_max - global_min));
            // Calculate max difference using the current array's maximum and the global minimum
            max_diff = max(max_diff, abs(global_max - curr_min));

            // Update global minimum and maximum
            global_min = min(global_min, curr_min);
            global_max = max(global_max, curr_max);
        }
        
        return max_diff;
    }
};