class MinStack {
public:
    stack<int> s;
    stack<int> s_copy;
    MinStack() {
        
    }
    void push(int value) {
        s.push(value);
        if(s_copy.empty() || value<=s_copy.top()){
            s_copy.push(value);
        }
    }
    
    void pop() {
        int x=s.top();
        s.pop();
        if(x== s_copy.top()) s_copy.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_copy.top();
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