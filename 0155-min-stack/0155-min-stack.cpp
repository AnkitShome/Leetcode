class MinStack {
    stack<pair<int,int>> st;
    int mini=INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        mini=val;
        if(!st.empty())
            mini=min(st.top().second,mini);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */