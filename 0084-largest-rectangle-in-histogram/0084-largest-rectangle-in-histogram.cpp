class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> nse(n, n);
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                nse[st.top()] = i;
                maxArea = max(maxArea, heights[st.top()] * (nse[st.top()] - pse[st.top()] - 1));
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
        while(!st.empty()){
            maxArea = max(maxArea, heights[st.top()] * (n - pse[st.top()] - 1));
            st.pop();
        } // this is how i solved
        return maxArea;
    }
};