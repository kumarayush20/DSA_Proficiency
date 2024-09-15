class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mpp;
        // 00000 ---> u, o, i, e, a

        // vector<int> state(5,0); // a,e,i,o,u

        int mask = 0; //00000
        mpp[mask] = -1;

        //string currState = "00000"

        int result = 0;

        for(int i=0; i<s.length(); i++){ //O(n)
            if(s[i] == 'a'){
                mask = (mask ^ (1<<0)); 
                // state[0] = (state[0] + 1)%2
                // state[o] = (state[1] ^ 1);
            }
            else if(s[i] == 'e'){
                mask = (mask ^ (1<<1)); 
            }
            else if(s[i] == 'i'){
                mask = (mask ^ (1<<2)); 
            }
            else if(s[i] == 'o'){
                mask = (mask ^ (1<<3)); 
            }
            else if(s[i] == 'u'){
                mask = (mask ^ (1<<4)); 
            }

            if(mpp.find(mask) != mpp.end()){
                result = max(result, i - mpp[mask]);
            }
            else{
                mpp[mask] = i;
            } 

            /*
            currState = ""
            for(int j=0; j<5; j++){
                currState += to_string(state[i]); // "00011"
            }

            if(mpp.find(currState) != mpp.end()){
                result = max(result, i - mpp[currState]);
            }
            else{
                mpp[currState] = i;
            }
            */
        }
        return result;
    }
};

//We cant do sliding window cuz standard nhi hai shrinking logic