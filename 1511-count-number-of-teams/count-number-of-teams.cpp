/* 
1 more logic to apply is before i and after i, jitne satisfy krenge condition, utne ka multiplication is gonna be added to ans,
to calculate the permutations.
*/
class Solution {
public:
    int numTeams(vector<int>& teams) {
        int n = teams.size();
        int ans = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int lessLeft = 0, moreLeft = 0;
            int lessRight = 0, moreRight = 0;
            
            for (int j=0; j<i; j++) {
                if (teams[j] < teams[i]) lessLeft++;
                if (teams[j] > teams[i]) moreLeft++;
            }
            
            for (int k = i+1; k<n; k++) {
                if (teams[k] < teams[i]) lessRight++;
                if (teams[k] > teams[i]) moreRight++;
            }
            
            ans += lessLeft * moreRight + moreLeft * lessRight;
        }
        
        return ans;
    }
};