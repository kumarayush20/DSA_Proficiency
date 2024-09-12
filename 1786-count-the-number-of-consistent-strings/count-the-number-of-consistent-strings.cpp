class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mpp;
        for(char it : allowed){
            mpp[it]++;
        }

        int cnt = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            string temp = words[i];
            int m = temp.size();
            bool flag = true;
            for(int j=0; j<m; j++){
                char ch = temp[j];
                if(mpp.find(ch)==mpp.end()){
                    flag = false;
                    break;
                }
            }
            if(flag==true) cnt++;
        }

        return cnt;
    }
};