class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxLen = 0, maxFreq = 0;
        vector<int> hash (26, 0);
        while(r<s.size()){
            hash[s[r] -'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);

            if(r-l+1 - maxFreq > k){
                hash[s[l]-'A']--;
                l = l+1;
            }
            if(r-l+1 - maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            }
            r = r+1;
        }
        return maxLen;
    }
};