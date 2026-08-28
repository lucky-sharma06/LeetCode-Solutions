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
            next = prev = nullptr;
        }
};
// Initialization of the DLL
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

// Insertion of Nodes in the DLL
Node* insBeforeHead(Node* head, int val){
    if(head == nullptr){
        Node* new_node = new Node(val);
        return new_node;
    }
    Node* new_node = new Node(val, head, nullptr);
    head -> prev = new_node;
    return new_node;
}

Node* insBeforeTail(Node* head, int val){
    if(head == nullptr){
        Node* new_node = new Node(val);
        return new_node;
    }
    if(head -> next == nullptr){
        return insBeforeHead(head, val);       
    }
    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    // tail points the tail
    Node* new_node = new Node(val, tail, tail -> prev);
    tail -> prev -> next = new_node;
    tail -> prev = new_node;
    return head;
}

Node* insBeforeK(Node* head, int val, int k){
    if(k == 1){
        return insBeforeHead(head, val);
    }   
    int cnt = 0; 
    Node* ptr = head;
    while(ptr != nullptr){
        cnt++;
        if(cnt == k) break;
        ptr = ptr -> next;
    }
    if(ptr == nullptr) return head;
    // ptr is at the kth element
    Node* new_node = new Node(val, ptr, ptr -> prev);
    ptr -> prev -> next = new_node;
    ptr -> prev = new_node;
    return head;
}

void insBeforeNode(Node* node, int val){
    Node* new_node = new Node(val, node, node -> prev);
    node -> prev -> next = new_node;
    node -> prev = new_node;
}
int main(){
    vector<int> arr = {5, 6, 7, 8, 9};
    Node* head = arrayToDLL(arr);
    print(head);
    head = insBeforeHead(head, 99);
    print(head);
    head = insBeforeTail(head, 999);
    print(head);
    head = insBeforeK(head, 1000, 3);
    print(head);
    insBeforeNode(head -> next -> next, 12000);
    print(head);
    return 0;
}