class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jumpNeeded = 1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < jumpNeeded){
                // means i can't make the jumb from here
                jumpNeeded++;
            }
            else{
                jumpNeeded = 1;
            }
        }
        if(jumpNeeded == 1){
            return true;
        }
        else{
            return false;
        }
    }
};