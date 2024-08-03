class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs based on the second element
        sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        });

        int prevEnd = pairs[0][1];
        int maxi = 1; // At least one pair can always be in the chain

        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > prevEnd) {
                // This pair can extend the chain
                prevEnd = pairs[i][1];
                maxi++;
            }
        }
        return maxi;
    }
};