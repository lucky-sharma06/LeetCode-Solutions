#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};
Node* arrayToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}   

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* temp = head;
    Node* front = nullptr;
    while(temp != nullptr){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
void print(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* additionBrute(Node* head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(temp != nullptr){
        temp -> data = temp -> data + carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            temp -> data = 0;
        }
        temp = temp -> next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        head = reverseLL(head);
        newNode -> next = head;
        return newNode;
    }
    head = reverseLL(head);
    return head;
}

int helper(Node* temp){
    // this is the recursive function
    if(temp == nullptr){
        return 1;
    }
    int carry = helper(temp -> next);
    temp -> data += carry;
    if(temp -> data < 10){
        return 0;
    }
    temp -> data = 0;
    return 1;
}
Node* additionOptimal(Node* head){
    int carry = helper(head);
    if(carry == 1){
        // means new node to be added
        Node* newNode = new Node(1);
        newNode -> next = head;
        return newNode;
    }
    return head;
}
int main(){
    vector<int> arr = {9, 9, 9};
    Node* head1 = arrayToLL(arr);
    print(head1);
    Node* newhead = additionBrute(head1);
    print(newhead);
    Node* head2 = arrayToLL(arr);
    Node* head2 = additionOptimal(head2);
    print(head2);


}