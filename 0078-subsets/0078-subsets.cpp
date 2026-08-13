class Solution {
public:
    void subSet(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        subSet(idx + 1, nums, ans, ds); // pick
        ds.pop_back();
        subSet(idx + 1, nums, ans, ds); // non-pick

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subSet(0, nums, ans, ds);

        return ans;
    }
};