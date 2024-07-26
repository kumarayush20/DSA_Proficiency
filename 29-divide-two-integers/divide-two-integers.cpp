class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false;
        if(dividend<=0 && divisor>0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);
        long quotient = 0;
        while(n>=d){
            long cnt = 0; // will always be 0 cuz n>=d
            while(n >= (d << cnt+1)){
                cnt++;
            }
            quotient += (1<<cnt);
            n -= (d<<cnt);
        }

        if(quotient == (1<<31) && sign) return INT_MAX;
        if(quotient == (1<<31) && !sign) return INT_MIN;

        return sign ? quotient : -quotient;
    }
};