#include <stack>

class MyQueue {
public:
    stack<int> stk, tmp;
    void copy(stack<int> &a, stack<int> &b){
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
    }

    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        copy(stk, tmp);
        int top = tmp.top();
        tmp.pop();
        copy(tmp, stk);
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        copy(stk, tmp);
        int top = tmp.top();
        copy(tmp, stk);
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */