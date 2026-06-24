class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
    //
    }
    // push easy, pop costly approach if push >>>> top
    void push(int x) {
      s1.push(x);      
    }
    
    int pop() {
        if(!s2.empty()){
            int elem = s2.top();
            s2.pop();
            return elem;
        }
        else{
            // s1 -> s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            int elem = s2.top();
            s2.pop();
            return elem;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            // s1 -> s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */