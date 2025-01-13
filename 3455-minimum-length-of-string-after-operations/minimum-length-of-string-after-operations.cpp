class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        map<char, int> mpp;
        
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            int x = mpp[s[i]];
            if(x>=3){             
                if(x%2==1){
                    ans += x-1;
                    mpp[s[i]] -= x-1;
                }
                else{
                    ans += x-2;
                    mpp[s[i]] -= x-2;
                }
            }
        }
        
        return s.size() - ans;
    }
};