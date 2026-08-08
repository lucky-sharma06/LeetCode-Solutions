class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 1;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int lastEnd = intervals[0][1];
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= lastEnd){
                cnt++;
                lastEnd = intervals[i][1];
            }
        }
        return n - cnt;
    }
};