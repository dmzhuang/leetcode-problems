class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        int min = x;
        if(!s.empty()) {
            min = getMin();
        }
        s.push(x <= min ? x : min);
        s.push(x);
    }

    void pop() {
        s.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        int top = s.top(); s.pop();
        int min = s.top();
        s.push(top);
        return min;
    }
private:
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */