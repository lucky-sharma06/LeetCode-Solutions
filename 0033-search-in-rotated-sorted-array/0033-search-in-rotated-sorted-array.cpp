class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // identify the sorted half
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                // left half is sorted
                // check for the target
                if(target >= nums[low] && target <= nums[mid]){
                    // target is in the left half
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                // right half is sorted
                // check for the target
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
        
    }
};