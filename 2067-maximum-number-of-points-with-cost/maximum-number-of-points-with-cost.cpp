class Solution {
private:
    int r, c;
    vector<vector<long long>> dp;
    vector<long long> left, right;
    long long f(int i, int j, vector<vector<int>>& points){
        if (i==0) return dp[i][j]=points[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        if (j==0) right_left_max(i, points);
        return dp[i][j]=max(left[j], right[j])+points[i][j];
    }

    void right_left_max(int i, vector<vector<int>>& points){
        // Compute max from left to col j=0...c-1
        left[0]=f(i-1, 0, points);
        for (int j=1; j < c; j++)
            left[j]=max(left[j-1]-1, f(i-1, j, points));

        // Compute max from right downto col j=c-1...0
        right[c-1]=f(i-1, c-1, points);
        for (int j=c-2; j >= 0; j--)
            right[j] = max(right[j+1]-1, f(i-1, j, points));
    }

public:
    long long maxPoints(vector<vector<int>>& points) {
        r=points.size(), c=points[0].size();
        dp.assign(r, vector<long long>(c, -1));
        left.assign(c, LLONG_MIN);
        right=left;

        long long ans=0;
        for (int j=0; j<c; j++)
            ans=max(ans, f(r-1, j, points));
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

/*
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(n, 0);

        // Initialize dp with the first row
        for (int j = 0; j < n; ++j) {
            dp[j] = points[0][j];
        }

        // Traverse through each row
        for (int i = 1; i < m; ++i) {
            vector<long long> leftMax(n), rightMax(n), newDp(n);
            
            // Calculate left max
            leftMax[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1], dp[j] + j);
            }
            
            // Calculate right max
            rightMax[n - 1] = dp[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1], dp[j] - j);
            }
            
            // Calculate new DP for the current row
            for (int j = 0; j < n; ++j) {
                newDp[j] = max(leftMax[j] - j, rightMax[j] + j) + points[i][j];
            }
            
            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
*/