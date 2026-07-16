#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> st;
    string exp;
    cin >> exp;

    for(int i = exp.length() - 1; i >= 0; i--){
        if(isalnum(exp[i])){
            st.push(string(1, exp[i]));
        }
        else{
            // operator
            // top1 + top2 + operator
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            st.push(t1 + t2 + string(1, exp[i]));
        }
    }
    cout << st.top();
    return 0;
}