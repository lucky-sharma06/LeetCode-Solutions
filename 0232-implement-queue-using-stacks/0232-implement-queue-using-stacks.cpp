class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
    //
    }
    
    void push(int x) {
      int s = s1.size();
      for(int i = 1; i <= s; i++){
        s2.push(s1.top());
        s1.pop();
      }   // s1 -> s2
      s1.push(x); // x -> s1
      // s2 -> s1;
      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
      
    }
    
    int pop() {
        int elem = s1.top();
        s1.pop();
        return elem;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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