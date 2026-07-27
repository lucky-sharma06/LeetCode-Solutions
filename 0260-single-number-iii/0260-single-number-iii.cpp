class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        long long totalXor = 0;
        for(int i : nums){
            totalXor ^= i;
        }
        // now totalXor is holding the xor of 2 different numbers which we have to find...
        long long rightMost = (totalXor & (totalXor - 1)) ^ totalXor;
        int b1 = 0;
        int b2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightMost){
                // b1 is the bucket which contains the numbers whose rightmost bit is set
                b1 = b1 ^ nums[i];
            }
            else{
                // b2 is the bucket which contains the numbers whose rightmost bit is not set;
                b2 = b2 ^ nums[i];
            }
        }
        return {b1, b2};
    }
};