class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        map<int, int> mpp;
        
        for(int i=0; i<n; i++){
            mpp[nums1[i]]++;
        }
        for(int i=0; i<m; i++){
            if(mpp[nums2[i]]>0){
                ans.push_back(nums2[i]);
                mpp[nums2[i]]--;
            }
        }
        return ans;
    }
};