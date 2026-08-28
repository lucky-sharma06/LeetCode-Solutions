#include<iostream>
#include<vector>
using namespace std;
// struct Node{
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
Node* arrayToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        // mover = temp; or
        mover = mover -> next;
    }
    return head;
}
void print(Node* head){
    while(head != nullptr){
        cout << head -> data;
        head = head -> next;
    }
    return;
}
Node* sortLL(Node* head){
    if(head == nullptr || head -> next == nullptr) return head;
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;

    while(head != nullptr){
        if(head -> data == 0){
            zero -> next = head;
            zero = head;
            head = head -> next;
        }
        else if(head -> data == 1){
            one -> next = head;
            one = head;
            head = head -> next;
        }
        else{
            two -> next = head;
            two = head;
            head = head -> next;
        }

        
    }
    // now we have 3 seperate linked list 
    zero -> next = onehead -> next ? onehead -> next : twohead -> next;;
    one -> next = twohead -> next;
    two -> next = nullptr;
    return zerohead -> next;
    
}
int main(){
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node* head = arrayToLinkedList(arr);
    print(head);
    head = sortLL(head);
    cout << endl;
    print(head);
    return 0;
}