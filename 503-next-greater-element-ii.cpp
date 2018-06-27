typedef struct ELEM {
    int index;
    int value;
} ELEM;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<ELEM> st;
        ELEM temp;
        map<int, int> m_map;
        map<int, int>::iterator it;
        vector<int> ans;
        int n = nums.size(), i;

        for(i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];
            while(!st.empty() && st.top().value < curr) {
                m_map.insert(std::pair<int, int> (st.top().index, curr));
                st.pop();
            }
            temp.index = i; temp.value = curr;
            st.push(temp);
        }

        for(i = 0; i < n; i++) {
            it = m_map.find(i);
            if(it != m_map.end()) ans.push_back(it->second);
            else ans.push_back(-1);
        }
        return ans;
    }
};