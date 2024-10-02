// Approach - 02 [ Using Sorting ]
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        // create a copy of a
        vector<int> arr_copy = a;

        // sort it
        sort(arr_copy.begin(), arr_copy.end());

        // assign rank from front 
        int rank = 1;
        // store it in map
        unordered_map<int,int> um;
        for(int i=0;i<arr_copy.size();i++){
            // check if the element is already present
            // ( avoid duplicate rank to same number)
            if(um.find(arr_copy[i]) == um.end()){
                um[arr_copy[i]] = rank;
                rank++;
            }
        }

        // traverse on array and assign them
        // rank based on map
        vector<int> ans(a.size());
        for(int i=0;i<a.size();i++){
            ans[i] = um[a[i]];
        }

        // return the ranks
        return ans;
    }
};