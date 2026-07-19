class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();   
        string ans = "";
        stack<char> st;
        // n size ki string
        int i = 0;
        while(num[i] != '\0'){
            while(!st.empty() && k > 0 && num[i] < st.top()){
                st.pop();
                k--;
                // stack me elements hai, k > 0 hai and current number is smaller or equal 
                // so pop();
            }
            st.push(num[i]);
            i++;
        }
        while(k > 0){
            k--;
            st.pop();
        }
        if(st.empty()) return "0";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        // agar string empty() ho to return "0"
        if(ans.empty()) return "0";
        return ans;
        // now the string is there but in reverse order
        // and will definitely have leading zeroes at the back
        // "91210000"
        // now the stack is ready 
        // int idx = n - 1;
        // while(!st.empty()){
        //     ans[idx] = st.top()
        //     st.pop();
        //     idx--;
        // }
        // ans = ans.substr(idx + 1); this is a way to take input from back of the string


        
        
    }
};