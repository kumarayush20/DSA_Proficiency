class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int cnt = 0;
        int left = ceil(sqrt(l)), right = sqrt(r);
        int ans = r-l+1;

        vector<int> prime(right+1, 1);
        prime[0] = prime[1] = 0;
        for(int i=2; i*i<=right; i++){
            if(prime[i]==1){
               for(int j=i*i; j<=right; j+=i){
                    prime[j]=0;     
               }
            }
        }

        for(int i=left; i<=right; i++){
            if(prime[i]){
                cnt++;
            }
        }

        ans = ans - cnt;
        return ans;

    }
};