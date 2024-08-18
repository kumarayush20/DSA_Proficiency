class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2,3,5};
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        unordered_set<long> visited;

        uglyHeap.push(1);
        visited.insert(1);

        long curr;
        for(int i=0; i<n; i++){
            curr = uglyHeap.top();
            uglyHeap.pop();
            for(int prime : primes){
                long new_curr = curr * prime;
                if(!visited.count(new_curr)){
                    uglyHeap.push(new_curr);
                    visited.insert(new_curr);
                }
            }
        }
        return (int)curr;
    }
};