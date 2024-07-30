class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ans = 0;
        if(s.size()==0) return ans;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && (st.top()=='b' && s[i]=='a')){
                st.pop();
                ans++;
            }
            else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};