class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ans, i;
        for(i = 0; i < size-1; i++) {
            s2.push(s1.top()); s1.pop();
        }
        ans = s1.top(); s1.pop();
        for(i = 0; i < size-1; i++) {
            s1.push(s2.top()); s2.pop();
        }
        size--;
        return ans;
    }

    /** Get the front element. */
    int peek() {
        int ans, i;
        for(i = 0; i < size-1; i++) {
            s2.push(s1.top()); s1.pop();
        }
        ans = s1.top();
        for(i = 0; i < size-1; i++) {
            s1.push(s2.top()); s2.pop();
        }
        return ans;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
private:
    stack<int> s1;
    stack<int> s2;
    int size;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */