#include<iostream>
using namespace std;

class queueImp{
    public:
        int size = 5; int curSize = 0;
        int front = -1, rear = -1;
        int arr[5]; 

    public:
        void push(int val){
            if(curSize == size){
                cout << "Overflow\n";
                return;
            }
            if(curSize == 0){
                front = rear = 0;
            }
            else{
                rear = (rear + 1) % size;
            }
            arr[rear] = val;
            curSize++;
        }

        int pop(){
            if(curSize == 0){
                cout << "Underflow\n";
                return -1;
            }
            int elem = arr[front];
            if(curSize == 1){
                front = rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
            curSize -= 1;
            return elem;   
        }

        int top(){
            if(curSize == 0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }
};
int main(){
    queueImp q;
    q.push(2);
    q.push(4);
    q.push(1);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.curSize << endl;
    cout << q.top() << endl;
    return 0;
}