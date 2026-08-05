class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // my attempt
        int cnt = 0;
        int child = 0;
        int cookie = 0;

        // sort both
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(cookie < s.size() && child < g.size()){
            if(s[cookie] >= g[child]){
                cnt++; // cookie assigned
                child++;
                cookie++;
            }
            else{
                cookie++;
            }
        }
        return cnt;
    }
};