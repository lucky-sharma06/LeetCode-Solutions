#include<iostream>
#include<vector>
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
Node* arrToLL(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* mover = head;
    for(int i = 1; i < v.size(); i++){
        Node* new_node = new Node(v[i]);
        mover -> next = new_node;
        mover = mover -> next;
    }
    return head;
}
void print(Node* head){
    Node* ptr = head;
    while(ptr){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}
Node* insertBeginning(Node* head, int val){
    // Node* new_node = new Node(val);
    // new_node -> next = head;
    Node* new_node = new Node(val, head);
    return new_node;
}

Node* insertAtK(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){
            Node* head = new Node(val);
            return head;
        }
    }
    if(k == 1){
        Node* new_node = new Node(val, head);
        return new_node;
    }
    Node* ptr = head;
    
    int cnt = 1;
    while(ptr != NULL){
        cnt++;
        if(k == cnt){
            Node* new_node = new Node(val, ptr -> next);
            ptr -> next = new_node;
            break;
        }
        ptr = ptr -> next;
    }
    return head;
} 
Node* insertLast(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* ptr = head;
    while(ptr -> next != nullptr){
        ptr = ptr -> next;
    }
    Node* new_node = new Node(val);
    ptr -> next = new_node;
    return head;
}
Node* insertBeforeNum(Node* head, int val, int num){
    if(head == NULL) return NULL;
    if(head -> data == num){
        return new Node(val, head);
    }
    Node* ptr = head;
    while(ptr -> next != nullptr){
        if(ptr -> next -> data == num){
            Node* new_node = new Node(val, ptr -> next);
            ptr -> next = new_node;
            break;
        }
        ptr = ptr -> next;
    }
    
    return head;
}
int main(){
    vector<int> v = {5, 6, 7, 8, 9};
    Node* head = arrToLL(v);
    print(head);
    head = insertBeginning(head, 1);
    // after insertion at the beginning
    print(head);
    head = insertLast(head, 10);
    // after insertion at the end
    print(head);
    head = insertAtK(head, 99, 10);
    print(head);
    head = insertBeforeNum(head, 1000, 10);
    print(head);
    return 0;
}