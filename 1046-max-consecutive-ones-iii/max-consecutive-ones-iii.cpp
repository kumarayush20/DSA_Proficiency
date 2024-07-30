class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, zeroes = 0;
        int l = 0, r = 0;
        int n = nums.size();
        while(r<n){
            int len = 0;
            if(nums[r]==0) zeroes++;
            if(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            else{
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};