class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }

        sort(nums.begin(), nums.end(), [&](int &n1, int &n2){
            if(mpp[n1]!=mpp[n2]){
                return mpp[n1] < mpp[n2];
            }
            else{
                return n1 > n2;
            }
        });
        
        return nums;
    }
};