class Solution {
public:
    int minimumPushes(string word) {
        vector<int> small(26, 0);
        for (char ch : word) {
            small[ch - 'a']++;
        }

        sort(small.begin(), small.end(), greater<int>());
        
        int ans = 0;
        int cnt = 0;
        
        for (int i = 0; i < small.size(); i++) {
            if (small[i] > 0) {
                if (cnt < 8) {
                    ans += 1 * small[i];
                } else if (cnt < 16) {
                    ans += 2 * small[i];
                } else if (cnt < 24) {
                    ans += 3 * small[i];
                } else {
                    ans += 4 * small[i];
                }
                cnt++;
            } else {
                break;
            }
        }     
       return ans;
    }
};