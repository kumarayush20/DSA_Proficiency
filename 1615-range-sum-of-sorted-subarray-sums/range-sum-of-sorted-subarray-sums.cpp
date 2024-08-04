class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<long long> subArrSum;
        for(int i=0; i<n; i++){
            long long arrEl = 0;
            for(int j=i; j<n; j++){
                arrEl += nums[j];
                subArrSum.push_back(arrEl);
            }
        }

        sort(subArrSum.begin(), subArrSum.end());
        long long sum = 0;
        for(int i=left-1; i<right; i++){
            sum = (sum + subArrSum[i]) % MOD;
        }
        return sum;
    }
};