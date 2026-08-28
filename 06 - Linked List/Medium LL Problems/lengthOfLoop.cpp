#include<iostream>
#include<unordered_map>
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
    void print(Node* head){
        while(head != nullptr){
            cout << head -> data << " ";
            head = head -> next;
        }
        return;
    }


    // -------- Linked List Definition ---------- // 

    int BruteSolution(Node* head){
        unordered_map<Node*, int> mp;
        Node* temp = head;
        int cnt = 1;
        while(temp != nullptr){
            if(mp.find(temp) != mp.end()){
                return cnt - mp[temp];
            }
            mp[temp] = cnt++;
            temp = temp -> next;
        }
        return 0; // if no cycle
    }

    int OptimalSolution(Node* head){
        Node* slow = head;
        Node* fast = head;
        int cnt = 1;
        bool isLoop = false;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                isLoop = true;
                break;
            }
            
        }
        // at this point we are at collision point
        if(isLoop){
            slow = slow -> next;
            while(slow != fast){
                slow = slow -> next;
                cnt++;
            }
            return cnt;
        }
        return 0;
            

    }
int main(){
    Node* head = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);

    // Linking the nodes
    head -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;

    // complete the cycle
    six -> next = nullptr;

    // to print the linked list
    // print(head);
    cout << BruteSolution(head) << endl;

    cout << OptimalSolution(head) << endl;
    return 0;
}