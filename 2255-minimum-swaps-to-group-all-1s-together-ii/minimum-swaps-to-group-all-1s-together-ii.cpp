class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        int totalOnes = accumulate(begin(nums), end(nums), 0); // window size containing all ones

        int currOnes = 0, maxCnt = 0;
        int l=0, r=0;
        while(r < 2*n){
            if(nums[r%n]==1){
                currOnes++;
            }

            if(r-l+1 > totalOnes){
                currOnes -= nums[l%n];
                l++;
            }
            maxCnt = max(maxCnt, currOnes);
            r++;
        }      
        int minSwaps = totalOnes - maxCnt;
        return minSwaps;
    }
};