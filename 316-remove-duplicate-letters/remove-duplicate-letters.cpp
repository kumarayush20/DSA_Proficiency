class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastSeen(26,0);
        vector<bool> inStack(26, false);
        stack<char> st;
        int size = s.size();

        for(int i=0; i<size; i++){
            lastSeen[s[i]-'a'] = i;
        }

        for(int i=0; i<size; i++){
            char ch = s[i];

            if(inStack[ch - 'a']) continue;

            while(!st.empty() && st.top()>ch && i<lastSeen[st.top()-'a']){
                inStack[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            inStack[ch-'a'] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans ;
            st.pop();
        }
        return ans;
    }
};