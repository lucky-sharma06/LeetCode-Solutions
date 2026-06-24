class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // traversing the string
        for(int i = 0; i < s.length(); i++){
            // push opening brackets into the stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                // closing bracket hai 
                if(st.empty()) return false;// and stack empty hai means false ex: s = "())"
                char ch = st.top();
                st.pop();
                if((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')){
                    // matching hai it means ok;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty(); // empty hai to true ni hai to false

    }
};