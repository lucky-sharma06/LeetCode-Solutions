class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(first == nums.size() || nums[first] != target){
            // target is not in the array
            return ans;
        }

        ans[0] = first;
        ans[1] = last - 1;
        return ans;
    }
};