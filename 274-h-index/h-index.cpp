class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max1 = 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i=0; i<n; i++){
            if(citations[i]>=n-i){
                max1 = max(max1, n-i);
            }
        }
        return max1;
    }
};