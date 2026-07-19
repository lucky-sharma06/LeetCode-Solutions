class Solution {
public: 
    vector<int> NSE(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int>& heights){
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }   
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Brute Force Solution
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int maxi = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};