class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        bool ans = false;
        int sum1 = 0, sum2 = 0;
        int sum3 = 0, sum4 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=10){
                sum1 += nums[i];
                sum3 += nums[i];
            }
            else{
                sum2 += nums[i];
                sum4 += nums[i];
            }
        }
        if(sum1>sum2 || sum3<sum4) ans = true;

        return ans;
    }
};