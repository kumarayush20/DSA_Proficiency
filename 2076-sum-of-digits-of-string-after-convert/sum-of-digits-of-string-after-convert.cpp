class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(int i=0; i<s.size(); i++){
            num += to_string(s[i] - 'a' + 1);
        }
        while(k--){
            int temp = 0;
            for(char ch : num){
                temp += ch - '0';
            }
            num = to_string(temp);
        }
        return stoi(num);
    }
};