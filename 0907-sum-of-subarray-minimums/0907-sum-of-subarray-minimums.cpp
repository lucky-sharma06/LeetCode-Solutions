class Solution {
public:
    vector<int> PSEE(vector<int> &arr){
        stack<int> st;
        vector<int> psee(arr.size());

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){  
                /// we are looking for previous smaller or equal so anything greater will be poped
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }
    vector<int> NSE(vector<int> &arr){
        stack<int> st;
        vector<int> nse(arr.size());
        
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                // we are looking for next smaller so anything >= should be poped
                st.pop();
            }
            if(st.empty()){
                nse[i] = arr.size();
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> psee = PSEE(arr);
        vector<int> nse = NSE(arr);
        int n = arr.size();
        int total = 0;
        const int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total % mod + (1LL * left * right * arr[i]) % mod) % mod;
        }
        return total;
    }
};