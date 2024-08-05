class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt = 0;
        string ans = "";
        map<string,int> mpp;
        for(auto &str : arr){
            mpp[str]++;
        }

        for(auto &str : arr){
            if(mpp[str] == 1){
                cnt++;
                if(cnt==k){
                    ans = str;
                    break;
                }
            }
        }
        return ans;
    }
};