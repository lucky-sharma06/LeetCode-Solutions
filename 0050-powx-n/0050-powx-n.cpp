class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = n;
        m = abs(m);
        while(m > 0){
            if(m & 1 == 1){
                // odd
                ans = ans * x;
                m--;
            }
            else{
                // even
                m = m / 2;
                x = x * x;
            }
        }
        if(n < 0){
            ans = 1.0/ans;
        }
        return ans;
    }
};