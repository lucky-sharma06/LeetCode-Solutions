#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> st;
    int i = 0; 
    string exp;
    cin >> exp;

    while(i < exp.length()){
        if(isalnum(exp[i])){
            st.push(string(1, exp[i]));
            // operand
        }
        else{
            // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t2 + string(1, exp[i]) + t1 + ")");

        }

        i++;
    }
    cout << st.top();
    return 0;


    
}