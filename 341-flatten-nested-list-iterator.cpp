/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size(), i;
        _next.clear();
        for(i = 0; i < size; i++) {
            vector<int> temp = Traversal(nestedList[i]);
            _next.insert(_next.end(), temp.begin(), temp.end());
        }
    }

    int next() {
        int ans = _next.front();
        _next.erase(_next.begin());
        return ans;
    }

    bool hasNext() {
        return _next.size() > 0;
    }
private:
    vector<int> Traversal(const NestedInteger& nestedInteger) {
        vector<int> ans;
        stack<NestedInteger> st;
        st.push(nestedInteger);

        do {
            while(!st.empty() && !st.top().isInteger()) {
                NestedInteger temp = st.top();
                st.pop();
                vector<NestedInteger> list = temp.getList();
                int size = list.size();
                for(int i = size-1; i >= 0; i--) {
                    st.push(list[i]);
                }
            }
            if(st.empty()) break;
            ans.push_back(st.top().getInteger());
            st.pop();
        } while(!st.empty());

        return ans;
    }
private:
    vector<int> _next;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */