class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, jumps = 0;
        int l = 0, r = 0;
        while(r < nums.size() - 1){
            for(int i = l; i <= r; i++){
                farthest = max(farthest, nums[i] + i);
            }
            // i got the farthest in the range
            // l -> r + 1;
            // r -> farthest
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};