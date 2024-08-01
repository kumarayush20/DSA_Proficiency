class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX, sIndex = -1;
        int l = 0, r = 0, cnt = 0;
        int n = s.size(), m = t.size();
        vector<int> hash(256, 0);
        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt = cnt+1;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt = cnt - 1;
                l = l+1;
            }          
            r = r+1;
        }

        return (sIndex==-1) ?  "" : s.substr(sIndex, minLen);
    }
};