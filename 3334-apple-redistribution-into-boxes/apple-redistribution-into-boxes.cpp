class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int i=0; i<apple.size(); i++){
            sum += apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum2 = 0; 
        int ans = 0;
        for(int i=0; i<capacity.size(); i++){
            sum2 += capacity[i];
            ans++;
            if(sum2>=sum){
                break;
            }
        }
        return ans;
    }
};