class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        // now count the no. of set bits
        int cnt = 0;
        while(ans > 0){
            ans = ans & (ans - 1);
            cnt++;
            ans >> 1;
        }

        return cnt;
    }
};