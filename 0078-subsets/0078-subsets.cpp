class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        int n = nums.size();
        int totalSubset = (1 << n);

        for(int i = 0; i < totalSubset; i++){
            vector<int> subset;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    // means the jth bit is set
                    subset.push_back(nums[j]);
                }
            }
            powerSet.push_back(subset);
        }
        return powerSet;
    }
};