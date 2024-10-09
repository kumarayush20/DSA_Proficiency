class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for (char i : s) {
            if (i == '('){
                st.push(i);
            }              
            else {
                if (st.empty())
                    cnt++;
                else
                    st.pop();
            }
        }
        return cnt + st.size();
    }
};