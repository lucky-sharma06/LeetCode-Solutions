class Solution {
public:
    int larRecHist(vector<int> &arr){
        int maxArea = 0;
        int n = arr.size();
        stack<int> st;
        int nse = 0; 
        int pse = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                // we want < elements in the stack 
                int elem = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, arr[elem] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int elem = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, arr[elem] * (nse - pse - 1));
        }

        return maxArea;        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n));

        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int i = 0; i < m; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] - '0' == 0){
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }
        // prefixSum matrix is now ready
        // now we will continue passing the mat[i] to the function
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            maxArea = max(maxArea, larRecHist(prefixSum[i]));
        }
        return maxArea;
    }
};