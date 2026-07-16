#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

void postFix(stack<char> &st, string &ans, string &exp){
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
            while(!st.empty() && st.top() != '(' && (priority(exp[i]) < priority(st.top()) || (priority(exp[i]) == priority(st.top()) && exp[i] == '^'))){
                ans += st.top();
                st.pop();
                // if priority is equal + - / * will push in this
                // ^ will pop
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
}
int main(){
    stack<char> st;
    string ans = "";
    string exp; 
    cin >> exp;
    
    // reverse
    reverse(exp.begin(), exp.end());

    // swap brackets
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '('){
            exp[i] = ')';
        }
        else if(exp[i] == ')')
            exp[i] = '(';
    }

    // convert it to postFix
    postFix(st, ans, exp);
    // at last reverse it again
    reverse(ans.begin(), ans.end());
    cout << endl;
    cout << ans;
    return 0;
}