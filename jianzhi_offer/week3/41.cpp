class MinStack {
public:

    stack<int> value_stk;
    stack<int> min_stk;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(min_stk.empty() || x <= min_stk.top()) min_stk.push(x);
        value_stk.push(x);
    }
    
    void pop() {
        if(min_stk.empty() || value_stk.top() == min_stk.top()) min_stk.pop();
        value_stk.pop();
    }
    
    int top() {
        return value_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */