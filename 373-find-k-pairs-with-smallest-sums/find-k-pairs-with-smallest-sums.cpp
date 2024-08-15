class Solution {
    typedef pair<int, pair<int,int>> P;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap;

        int n = nums1.size();
        int m = nums2.size();

        set<pair<int, int>> st;
        vector<vector<int>> result;

        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0,0}});
        st.insert({0,0});

        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});

            if(i+1<n && st.find({i+1, j}) == st.end()){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                st.insert({i+1,j});
            }
            if(j+1<m && st.find({i, j+1}) == st.end()){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                st.insert({i,j+1});
            }
        }
        return result;
    }
};