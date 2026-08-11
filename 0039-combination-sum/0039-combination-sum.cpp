class Solution {
public:
    void findCombo(int idx, int target, vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr){
        // BASE CASE: 
        if(idx == arr.size()){
            // means at last node of the recursion tree
            if(target == 0){
                // combo is correct
                ans.push_back(ds);
            }
            // backtracking
            return;
        }

        if(arr[idx] <= target){
            // means picking
            ds.push_back(arr[idx]);
            findCombo(idx, target - arr[idx], ans, ds, arr);
            ds.pop_back();
        }
        findCombo(idx + 1, target, ans, ds, arr);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombo(0, target, ans, ds, candidates);
        return ans;
    }
};