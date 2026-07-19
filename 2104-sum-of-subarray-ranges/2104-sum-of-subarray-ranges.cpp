class Solution {
public:
    vector<int> PSEE(vector<int>& arr) {
        stack<int> st;
        vector<int> psee(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                /// we are looking for previous smaller or equal so anything
                /// greater will be poped
                st.pop();
            }
            if (st.empty()) {
                psee[i] = -1;
            } else {
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }
    vector<int> NSE(vector<int>& arr) {
        stack<int> st;
        vector<int> nse(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                // we are looking for next smaller so anything >= should be
                // poped
                st.pop();
            }
            if (st.empty()) {
                nse[i] = arr.size();
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    long long sumMin(vector<int>& arr) {

        vector<int> psee = PSEE(arr);
        vector<int> nse = NSE(arr);
        int n = arr.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (1LL * left * right * arr[i]));
        }
        return total;
    }

    vector<int> NGE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = n;
            } else {
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }

    vector<int> PGEE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pgee(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pgee[i] = -1;
            } else {
                pgee[i] = st.top();
            }
            st.push(i);
        }
        return pgee;
    }

    long long sumMax(vector<int>& arr) {
        vector<int> nge = NGE(arr);
        vector<int> pgee = PGEE(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            sum = sum + (1LL * left * right * arr[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};