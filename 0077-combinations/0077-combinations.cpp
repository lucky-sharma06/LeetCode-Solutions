class Solution {
public:
    void findCombo(int idx, int k, int n, vector<vector<int>>& ans, vector<int>& ds){
        if(k == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = idx + 1; i <= n; i++){
            ds.push_back(i);
            findCombo(i, k - 1, n, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombo(0, k, n, ans, ds);
        return ans;
    }
};