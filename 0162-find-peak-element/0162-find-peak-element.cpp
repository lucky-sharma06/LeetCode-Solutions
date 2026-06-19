class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Optimal
        int n = nums.size();
        int low = 1; int high = n - 2;
        if(n == 1) return 0; // single elemnt
        if(nums[0] > nums[1]) return 0; // first elem
        if(nums[n - 1] > nums[n - 2]) return n - 1; // last elem

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;

            if(nums[mid] > nums[mid - 1]){
                // increasing curve
                low = mid + 1;
            }
            else if(nums[mid] > nums[mid + 1]){
                // decreasing curve
                high = mid - 1;
            }
            else{
                // it is on the dip
                low = mid + 1;
            }
        }
        return -1;
    }
};