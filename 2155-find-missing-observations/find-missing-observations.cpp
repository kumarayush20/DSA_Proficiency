class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m+n);
        int sum2 = 0;
        for(auto it : rolls){
            sum2 += it;
        }
        int diff = sum - sum2;
        if(diff > 6*n || diff<n){
            return {};
        }
        int rem = diff % n;
        int div = diff/n;
        vector<int> ans(n, div);
        // Distribute the remainder by adding 1 to the first 'remainder' elements
        for (int i = 0; i<rem; ++i) {
            ans[i]++;
        }
        return ans;
    }
};