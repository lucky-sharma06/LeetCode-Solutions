#include<iostream>
using namespace std;

class Node{
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

class LLqueue{
    public: 
        Node* front = nullptr;
        Node* rear = nullptr;
        int size = 0;
    public: 
        void push(int val){
            Node* temp = new Node(val);
            if(front == nullptr){
                front = rear = temp; // first element push
            }
            else{
                rear -> next = temp;
                rear = temp;
            }
            size++;
        }

        void pop(){
            if(front == nullptr){
                cout << "Underflow\n";
                return;
            }
            Node* temp = front;
            front = front -> next;
            if(front == nullptr){ // if the last element is deleted
                rear = nullptr;
            }
            delete temp;
            size--;
        }

        int peek(){
            if(front == nullptr){
                cout << "Empty Queue" << endl;
                return -1;
            }
            return front -> data;
        }

        int Size(){
            return size;
        }
};
int main(){
    LLqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.Size() << endl;
    cout << q.peek() << " or " << q.front->data << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();


    return 0;
}