class Solution {
public:
    int func(vector<int> & nums, int low, int high, int target){
        if(low > high) return -1;
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return func(nums, mid + 1, high, target);
        else return func(nums, low, high - 1, target);
    }
    int search(vector<int>& nums, int target) { 
        // recursive 
        int low = 0;
        int high = nums.size() - 1;
        return func(nums, low, high, target);
    }
};