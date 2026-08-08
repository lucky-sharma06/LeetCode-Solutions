class Solution {
public:
    double helper(double x, long long m){
        if(m == 0) return 1;

        if(m & 1 == 1){
            // odd
            return x * helper(x * x, m / 2);
        }
        return helper(x * x, m / 2);
    }
    double myPow(double x, int n) {
        long long m = n;
        if(m < 0){
            return 1.0/helper(x, -m);
        }
        return helper(x, m);
    }
};