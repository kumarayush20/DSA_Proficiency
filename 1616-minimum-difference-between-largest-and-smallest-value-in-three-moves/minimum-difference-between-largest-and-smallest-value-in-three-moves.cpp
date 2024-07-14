class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, nums[(n - 1) - (3 - i)] - nums[i]); // subtracting rightmost and leftmost
        }
        return ans;
    }
};