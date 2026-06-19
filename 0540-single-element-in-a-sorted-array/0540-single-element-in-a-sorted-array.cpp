class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // using binary search
        int low = 1;
        int high = nums.size() - 2;

        // single element
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0]; // first element
        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1]; // last element
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            // (even, odd) left half
            if(((mid % 2 == 1) && (nums[mid] == nums[mid - 1])) || ((mid % 2 == 0) && (nums[mid] == nums[mid + 1]))){
                low = mid + 1;
            }
            // (odd, even) right half
            else{
                high = mid - 1;
            }
        }
        return 0;
    }
};