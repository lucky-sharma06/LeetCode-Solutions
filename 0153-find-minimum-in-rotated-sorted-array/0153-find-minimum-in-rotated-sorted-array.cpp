class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                // left half is sorted
                if(nums[low] < mini) mini = nums[low];
                low = mid + 1;
            }
            else{
                // right half is sorted
                if(nums[mid] < mini) mini = nums[mid];
                high = mid - 1;
            }
        }
        return mini;
    }
};