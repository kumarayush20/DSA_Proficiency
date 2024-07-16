class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false;
        int length = 0;

        for(int i=s.size()-1; i>=0; i--){
            if(s[i]!=' ') flag = true;
            if(flag){
                if(s[i]!=' ') length++;
                else break;
            }
        }
        return length;
    }
};