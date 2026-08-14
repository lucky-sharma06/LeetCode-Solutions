class Solution {
public:
    void findCombo(int idx, int k, int n, vector<vector<int>>& ans, vector<int>& ds){
        if(n == 0 && k == 0){ // base case
            ans.push_back(ds); // we are getting the sum
            return;
        }

        for(int i = idx + 1; i < 10; i++){
            if(i > n) break;
            k--;
            ds.push_back(i);
            findCombo(i, k, n - i, ans, ds);
            ds.pop_back();
            k++;
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds; // data structure
        findCombo(0, k, n, ans, ds);
        return ans;
    }
};