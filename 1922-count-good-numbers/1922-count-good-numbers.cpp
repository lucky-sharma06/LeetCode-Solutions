class Solution {
public:
    long long Power(long long x, long long m){
        long long mod = 1e9 + 7;
        if(m == 0){
            return 1;
        }
        if(((m & 1) == 1)){
            return (x * Power((x * x) % mod, m / 2)) % mod;
        }
        return (Power((x * x) % mod, m / 2) % mod);
    }
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long odd = Power(4, (n / 2)); // {1 3 5 7}
        long long even = Power(5, ((n + 1) / 2)); // {0 2 4 6 8}

        return (odd * even) % mod;
    }
};