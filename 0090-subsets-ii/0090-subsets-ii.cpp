class Solution {
public:
// we will use the subsequence approach now
    void subSet(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        // BASE CASE
        ans.push_back(ds);
        if(idx == nums.size()){
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            subSet(i + 1, nums, ans, ds);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subSet(0, nums, ans, ds);
        return ans;
    }
};