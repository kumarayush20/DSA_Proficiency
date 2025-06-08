class Solution {
private:
    vector<int> ans;
    void solve(int i, int n){
        // base conditon - where recursion gets over
        if(i>n){
            return;
        }

        int cur = i; // 1 
        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            string tmp = to_string(cur) + to_string(i); // 1 0 
            solve(stoi(tmp),n);

            // int tmp = cur*10 +  i;
            // solve(tmp,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        for(int i=1;i<=9;i++){
            solve(i,n);
        }

        return ans;
    }
};