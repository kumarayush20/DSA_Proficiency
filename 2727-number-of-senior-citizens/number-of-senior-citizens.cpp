class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0; i<details.size(); i++){
            string s1 = details[i];
            string s2 = s1.substr(11, 2);
            int n1 = stoi(s2);
            if(n1>60) cnt++;
        }
        return cnt;
    }
};