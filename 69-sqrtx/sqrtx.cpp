class Solution {
public:
    int mySqrt(int x) {
        long low = 1;
        long high = x;
        while(low<=high){
            long mid = (low+high)/2;
            if(mid<=x/mid){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};