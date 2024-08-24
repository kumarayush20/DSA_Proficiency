class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        int n = sentence.size();
        int cnt = 0;
        for(char &ch : sentence){
            int ind = ch - 'a';
            if(v[ind]==0){
                v[ind]++;
                cnt++;
            }
        }

        return (cnt==26) ? true : false;
    }
};