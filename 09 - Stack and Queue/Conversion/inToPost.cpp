#include<iostream>
#include<stack>
using namespace std;
int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}
int main(){
    stack<char> st;
    string ans = "";
    string exp; 
    cin >> exp;
    int i = 0;
    while(i < exp.length()){
        if(exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= '0' && exp[i] <= '9'){
            ans = ans + exp[i];
        }
        else if(exp[i] == '('){
            st.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop(); // pop (
        }
        else{
            while(!st.empty() && st.top() != '(' && (priority(exp[i]) < priority(st.top()) || (priority(exp[i]) == priority(st.top()) && exp[i] != '^'))){
                ans += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
        i++;
    }
    // at last if stack is not empty
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    cout << endl;
    cout << ans;
    return 0;
}