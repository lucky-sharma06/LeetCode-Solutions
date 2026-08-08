class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // [S1, E1] 
        // and [S2, E2] comes so the overlap condition will be 
        // S2 <= E1 && E2 >= S1
        // Consider the left middle(overlap) right part
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> result;
        while(i < n && newInterval[0] > intervals[i][1]){
            // S2 > E1 means no overlap
            // left part
            result.push_back(intervals[i]);
            i++;            
        }
        // out of here means i done or S2 <= E1
        while(i < n && newInterval[1] >= intervals[i][0]){
            // E2 >= S1
            // Overlap or middle part
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while(i < n){
            // this is the right part, since we pushed the new interval now the right must be pushed as it is
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};