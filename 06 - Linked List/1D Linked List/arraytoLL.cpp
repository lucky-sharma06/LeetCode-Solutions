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
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* ptr = head;
    while(ptr != nullptr){
        cnt++;
        ptr = ptr -> next;
    }
    return cnt;
}
int checkIfPresent(Node* head, int val){
    Node* ptr = head;
    while(ptr){
        if(ptr -> data == val) return 1;
        ptr = ptr -> next;
    }
    return 0;
}
int main(){
    vector<int> arr = {2, 4, 5, 6, 7};
    Node* head = arrayToLinkedList(arr);
    cout << head -> data << endl;
    Node* ptr = head;
    while(ptr){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
    cout << lengthOfLL(head) << endl;
    cout << checkIfPresent(head, 5) << endl;
    return 0;
}