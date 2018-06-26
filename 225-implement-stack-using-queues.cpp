class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans, i, size = q1.size();
        for(i = 0; i < size-1; i++) {
            q2.push(q1.front()); q1.pop();
        }
        ans = q1.front(); q1.pop();
        for(i = 0; i < size-1; i++) {
            q1.push(q2.front()); q2.pop();
        }
        return ans;
    }

    /** Get the top element. */
    int top() {
        int ans, i, size = q1.size();
        for(i = 0; i < size-1; i++) {
            q2.push(q1.front()); q1.pop();
        }
        ans = q1.front(); q1.pop();
        for(i = 0; i < size-1; i++) {
            q1.push(q2.front()); q2.pop();
        }
        q1.push(ans);
        return ans;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size() == 0;
    }
private:
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */