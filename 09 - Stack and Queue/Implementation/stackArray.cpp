#include<iostream>
using namespace std;
class stackImp{
    private: 
        int top = -1; int arr[10];
    public: 
        void push(int val){
            if(top == 9){
                cout << "Stack overflow" << endl;
                return; 
            }
            top++;
            arr[top] = val;
        }
        int peek(){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        void pop(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }
            top--;
        }
        int size(){
            return top + 1;
        }
};
int main(){
    stackImp st;
    st.push(5);
    st.push(3);
    st.push(1);
    cout << st.peek();
    st.pop();
    cout << st.size();
    st.pop();
    return 0;
}