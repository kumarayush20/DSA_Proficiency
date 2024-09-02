class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        long long n = chalk.size();
        for(int i=0; i<n; i++){
            sum += chalk[i];
        }

        long long rounds = k/sum;
        long long left = k%sum;
        long long ans;
        if(left==0) return 0;
        for(int i=0; i<n; i++){
            if(left < chalk[i]){
                ans = i;
                break;
            }
            left -= chalk[i];
        }
        return ans;
    }
};