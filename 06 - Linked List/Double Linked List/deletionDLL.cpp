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
// This is to initialize a DLL
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
// Deletion of Node in DLL
Node* deleteHead(Node* head){
    if(head == nullptr || head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = head -> next;
    head -> prev = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* ptr = head;
    while(ptr -> next -> next != nullptr){
        ptr = ptr -> next;
    }
    delete ptr -> next;
    ptr -> next = nullptr;
    return head;
}

Node* deleteK(Node* head, int k){
    // if ll has 0 or 1 element
    if(head == nullptr) return nullptr;
    if(k == 1){
        if(head -> next == nullptr){
            delete head;
            return nullptr;
        }
        Node* temp = head;
        head = head -> next;
        head -> prev = nullptr;
        delete temp;
        return head;
    }
    else{
        int cnt = 0;
        Node* ptr = head;
        while(ptr != nullptr){
            cnt++;
            if(k == cnt) break;
            ptr = ptr -> next;
        }
        // now ptr points at the kth point
        ptr -> prev -> next = ptr -> next;
        if(ptr -> next != nullptr){
            ptr -> next -> prev = ptr -> prev;
        }
        delete ptr;
        return head;
    }
}

Node* deleteNode(Node* head, int num){
    if(head == nullptr) return nullptr;
    if(head -> data == num){
        Node* temp = head;
        head = head -> next;
        if(head != nullptr) head -> prev = temp;
        delete temp;
        return head;
    }
    Node* ptr = head;
    while(ptr != nullptr){
        if(ptr -> data == num) break;
        ptr = ptr -> next;
    }
    // to check if ptr == null 
    if(ptr == nullptr) return head; // num is not present
    // at this point ptr points to the location of the required node
    if(ptr -> prev == nullptr){
        head = head -> next;
        head -> prev = nullptr;
        delete ptr;
        return head;
    }
    ptr -> prev -> next = ptr -> next;
    if(ptr -> next != nullptr){
        ptr -> next -> prev = ptr -> prev;
    }
    delete ptr;
    return head;

}
int main(){
    vector<int> arr = {1, 3, 4, 5, 6};
    Node* head = arrayToDLL(arr);
    print(head);
    // head = deleteHead(head);
    // print(head);
    // head = deleteTail(head);
    // print(head);
    // head = deleteK(head, 1);
    // print(head);
    head = deleteNode(head, 1);
    print(head);
    return 0;

}