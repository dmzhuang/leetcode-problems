class Solution {
public:
    using Elem = struct elem{
        int func;
        int start_time;
        int exclusive_time;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Elem> st;
        int nums = logs.size(), i;


        for(i = 0; i < nums; i++) {
            Elem temp = ExtractLog(logs[i]);
            int _func = temp.func, _event_time = temp.start_time;
            if(logs[i].find("start") != string::npos) {
                Elem elem; elem.func = _func, elem.start_time = _event_time; elem.exclusive_time = 0;
                st.push(elem);
            } else {
                Elem elem = st.top(); st.pop();
                int time_on_this_func = _event_time - elem.start_time + 1 - elem.exclusive_time;
                ans[elem.func] += time_on_this_func;
                if(!st.empty()) {
                    temp = st.top();
                    temp.exclusive_time += _event_time - elem.start_time + 1;
                    st.pop();
                    st.push(temp);
                }
            }
        }

        return ans;
    }
private:
    Elem ExtractLog(const string& log) {
        Elem elem;
        int pos = log.find(":");
        elem.func = stoi(log.substr(0, pos));

        pos = log.rfind(":");
        elem.start_time = stoi(log.substr(pos+1));

        return elem;
    }
};