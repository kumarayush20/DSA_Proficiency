// C++ using argument in Counting sort
const long long N=100001;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        bitset<N> hasX=0;
        int M=0;
        for(int x: nums){
            hasX[x]=1;
            M=max(M, x);
        }
        int maxStreak=0, Msqrt=sqrt(M);;
        for(long long x=2; x<=Msqrt; x++){
            if (hasX[x]==0) continue;
            int streak=1;
            for(long long z=x*x; z<=M; z*=z){
                if (hasX[z]) {
                    streak++;
                    hasX[z]=0;
                }
                else break;
            }
            maxStreak=max(maxStreak, streak);
            if (maxStreak==5) break;
        }
        return maxStreak<2?-1:maxStreak;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();