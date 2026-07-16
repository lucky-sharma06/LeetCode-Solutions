class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        // double the array approach
            
        for(int i = 0; i < nums.size(); i++){
            bool found = false;
            for(int j = i + 1; j <= i + nums.size() - 1; j++){
                int idx = j % nums.size();
                if(nums[idx] > nums[i]){
                    ans.push_back(nums[idx]);
                    found = true;
                    break;
                }
            }
            if(found == false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};