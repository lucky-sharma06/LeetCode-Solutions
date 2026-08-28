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
            next = NULL;
        }
};
Node* arrayToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        ptr -> next = temp;
        ptr = ptr -> next;
    }
    return head;
}
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    free(temp); // or delete temp;
    return head;
}
Node* removeTail(Node* head){
    if(head == NULL) return NULL;
    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}
Node* removeK(Node* head, int k){
    if(head == nullptr) return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
Node* removeVal(Node* head, int val){
    if(head == nullptr) return head;
    if(head -> data == val){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* ptr = head;
    Node* preptr = ptr;
    while(ptr != nullptr && ptr -> data != val){
        preptr = ptr;
        ptr = ptr -> next;
    }
    /* OR We can do like this also
    while(ptr){
    if(ptr -> data == val){
        preptr -> next = preptr -> next -> next;
        free(temp);
        break;
    }
    preptr = ptr;
    ptr = ptr -> next;
    }
    */
    preptr -> next = ptr -> next;
    free(ptr);
    return head;
}
int main(){
    vector<int> arr = {5, 6, 7, 8, 9};
    Node* head = arrayToLL(arr);
    // cout << head -> data << endl;
    // head = removeHead(head);
    // cout << head -> data << endl;
    // head = removeTail(head);
    // cout << head -> data << endl;
    // print(head);
    // head = removeK(head, 2);
    print(head);
    head = removeVal(head, 5);
    print(head);
    return 0;
}