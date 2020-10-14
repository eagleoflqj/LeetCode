class MinStack {
    stack<int> stk, min_stk;
public:
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        min_stk.push(min_stk.empty() ? x : min(min_stk.top(), x));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
