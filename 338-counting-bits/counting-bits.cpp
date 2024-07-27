class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n+1);
        t[0] = 0;
        for(int i=0; i<=n; i++){
            t[i] = t[i/2] + i%2;
        }
        return t;
    }
};