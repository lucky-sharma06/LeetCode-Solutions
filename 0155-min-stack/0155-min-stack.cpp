class MinStack {
public:
    stack<long long> st;
    long long mini;
    
    MinStack() {
        // constructor
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            // if it is not empty
            // if the value > mini then no problem
            if(value >= mini) st.push(value);
            else{
                // now the mini will modify 2*value - mini = newValue or modifiedValue
                st.push(2LL * value - mini); // now the mini is the top and min
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini){
            // means modified value
            mini = 2 * mini - x;
        }
        
    }
    
    int top() {
        long long x = st.top();
        if(x < mini) return mini;
        return x;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */