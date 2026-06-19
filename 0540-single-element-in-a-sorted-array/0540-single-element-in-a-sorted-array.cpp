class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        for(i = 0; i < nums.size(); i = i + 2){
            int j = i + 1;
            if(j == nums.size() || nums[i] != nums[j])
                break;
        }
        return nums[i];
        
    }
};