#include<iostream>
using namespace std;
class Node{// definition of a node
    public: 
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

class LLstack{
    public: 
        Node* top = nullptr;
        int size = 0;
    public: 
        void push(int val){
            Node* temp = new Node(val);
            temp -> next = top;
            top =  temp;
            size++;
        }

        void pop(){ // nullptr edge case also
            Node* temp = top;
            top = top -> next;
            delete temp;
            size--;
        }

        int peek(){ // nullptr edge case is left
            return top -> data;
        }   

        int Size(){
            return size;
        }
};
int main(){
    LLstack st;
    st.push(5);
    st.push(6);
    st.push(7);
    cout << st.peek() << " or " << st.top->data << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.Size() << endl; 
    return 0;
}