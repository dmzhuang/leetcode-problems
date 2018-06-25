// 解析:https://leetcode.com/problems/next-greater-element-i/discuss/97595/Java-10-lines-linear-time-complexity-O(n)-with-explanation

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        map<int, int> m_map;
        map<int, int>::iterator it;
        stack<int> s;
        int len = nums.size(), i;

        for(i = 0; i < len; i++) {
            while(!s.empty() && s.top() < nums[i]) {
                m_map.insert(pair<int, int>(s.top(), nums[i]));
                s.pop();
            }
            s.push(nums[i]);
        }
        len = findNums.size();
        for(i = 0; i < len; i++) {
            it = m_map.find(findNums[i]);
            if(it != m_map.end()) ans.push_back(it->second);
            else ans.push_back(-1);
        }
        return ans;
    }
};