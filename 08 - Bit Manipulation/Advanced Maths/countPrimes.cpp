class Solution {
public:
    int checkPrime(int num){
        int cnt = 0;
        for(int i = 1; i*i <= num; i++){
            if(num % i == 0){
                cnt++;
                if(num/i != i){
                    cnt++;
                }
            }
        }
        if(cnt == 2){
            return 1;
        }
        else{
            return 0;
        }
    }
    int countPrimes(int n) {
        // My Solution:
        int cnt = 0;
        if(n <= 1) return 0;
        for(int i = 2; i < n; i++){
            cnt += checkPrime(i);
        }
        return cnt;
    }
};
