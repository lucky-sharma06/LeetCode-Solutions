#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<string> st;
    string exp;
    cin >> exp;

    for(char ch : exp){
        if(isalnum(ch)){
            st.push(string(1, ch)); // string(3, '#') => ###
        }
        else{
            //operator
            // op + top2 + top1
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            st.push(string(1, ch) + t2 + t1);
        }
    }

    cout << st.top();
    return 0;
}