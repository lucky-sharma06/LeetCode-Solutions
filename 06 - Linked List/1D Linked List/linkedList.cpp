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

int main(){
    vector<int> arr = {2, 4, 5, 6, 7};
    Node* y = new Node(arr[0], nullptr);   
    // Node* y = new Node(arr[1]);   
    cout << y -> data;
    return 0;
}