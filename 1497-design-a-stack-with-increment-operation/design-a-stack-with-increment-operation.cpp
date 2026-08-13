class CustomStack {
public:
    stack<int> s;
    int c=0;
    int m;
    CustomStack(int maxSize) {
        this->m=maxSize;
    }
    
    void push(int x) {
        if(c >= m){
            return;
        }
        else{
            s.push(x);
            c++;
        }
    }
    
    int pop() {
        if(s.empty()) {
            return -1;
        }

        int x=s.top();
        s.pop();
        c--;
        return x;
    }
    
    void increment(int k, int val) {
        stack<int> s1;
        int count=0;
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty()){
            int x=s1.top();
            s1.pop();
            if(count < k){
                x=x+val;
                count++;
            }
            s.push(x);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */