class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        // Find the maximum element in the array
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
        }

        int maxCnt = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                cnt++; 
                maxCnt = max(cnt, maxCnt);
            } else {
                cnt = 0; 
            }
        }

        return maxCnt;
    }
};
