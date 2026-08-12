class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int i = 0;
        int n = nums.size(); 

        for(int j = 0; j < n; j++){
            if(nums[j] != val){
                // means put it to the index i
                nums[i] = nums[j];
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};