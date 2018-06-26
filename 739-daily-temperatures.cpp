
typedef struct Entry{
    int index;
    int value;
}Entry;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<Entry> s;
        map<int, int> m_map;
        map<int, int>::iterator it;
        int size = temperatures.size(), i;

        for(i = 0; i < size; i++) {
            while(!s.empty() && s.top().value < temperatures[i]) {
                m_map.insert(std::pair<int, int> (s.top().index, i));
                s.pop();
            }
            Entry entry;
            entry.index = i; entry.value = temperatures[i];
            s.push(entry);
        }

        for(i = 0; i < size; i++) {
            it = m_map.find(i);
            if(it != m_map.end()) ans.push_back(it->second - it->first);
            else ans.push_back(0);
        }
        return ans;
    }
};