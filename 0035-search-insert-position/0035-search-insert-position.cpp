class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    
        // basically a lower_bound question
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return index;
    }
};