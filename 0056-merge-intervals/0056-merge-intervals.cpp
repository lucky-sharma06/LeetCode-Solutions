class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++){
            if(result.empty() || intervals[i][0] > result.back()[1]){
                // then add it to the result
                result.push_back(intervals[i]);
            }
            else{
                // this is the overlap case
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};