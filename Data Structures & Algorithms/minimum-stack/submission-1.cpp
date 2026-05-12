class MinStack {
private:
    stack<int> sk;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        sk.push(val);
        val = min(val, (min_stack.empty()) ? val : min_stack.top());
        min_stack.push(val);
    }
    
    void pop() {
        sk.pop();
        min_stack.pop();
    }
    
    int top() {
        return sk.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
