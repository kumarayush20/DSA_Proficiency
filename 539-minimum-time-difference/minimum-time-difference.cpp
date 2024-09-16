class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i=0; i<n; i++){
            string time = timePoints[i];

            string hourSubstr = time.substr(0,2); //"HH"
            string minSubstr = time.substr(3); //"MM"

            int hourInt = stoi(hourSubstr);
            int minInt = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }

        sort(begin(minutes), end(minutes));

        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            ans = min(ans, minutes[i] - minutes[i-1]);
        }

        return min(ans, (24*60 - minutes[n-1]) + minutes[0]);
        // 23:59, 00:00
    }
};