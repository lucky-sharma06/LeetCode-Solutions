class Solution {
public:
    int divide(int dividend, int divisor) {
       // Striver's approach
        if(dividend == divisor) return 1;
        bool isPositive = true;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            // in that case negative
            isPositive = false;
        }

        long n = abs((long)dividend); // because it may abs(-2^31) = 2^31 and it is overflow int
        long d = abs((long)divisor);
        long ans = 0;
        while(n >= d){
            // means divisor can be subtracted
            int cnt = 0;
            // now we want to find largest which can be subtracted
            while(n >= (d << (cnt + 1))){ // eg- 7 3  => 7 <= 3 means 3 << 0 will obviously can be subtracted
                cnt++;
            }
            // we have found the highest count
            n = n - (d << cnt);
            ans += (1LL << cnt);
        }

        // now couple of edge cases
        if(ans >= (1LL << 31) && isPositive == true){
            return INT_MAX;
        }
        if(ans > (1LL << 31) && isPositive == false){
            return INT_MIN;
        }
        return isPositive ? ans : (-1 * ans);
    }
};