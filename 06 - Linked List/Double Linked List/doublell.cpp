#include<iostream>
#include<vector>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1, Node* next1, Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

Node* arrayToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* new_node = new Node(arr[i], nullptr, mover);
        mover -> next = new_node;
        mover = mover -> next;
    }
    return head;
}
void print(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}
int main(){
    vector<int> arr = {1, 3, 4, 5, 6};
    Node* head = arrayToDLL(arr);
    print(head);

}