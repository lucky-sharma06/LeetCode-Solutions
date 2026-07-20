class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        int nse = 0; 
        int pse = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                // first pop then see if stack is empty meaning no pse otherwise pse = st.top();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse -1));
        } // this is the optimal approach;
        return maxArea;
    }
};