class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> points;
        int len = ops.size(), i = 0;

        for(i = 0; i < len; i++) {
            if(ops[i] == "C") {
                points.pop();
            } else if(ops[i] == "D") {
                points.push(points.top() * 2);
            } else if(ops[i] == "+") {
                int top1 = points.top(); points.pop();
                int top2 = points.top(); points.push(top1);
                points.push(top1 + top2);
            } else {
                int val = atoi(ops[i].c_str());
                points.push(val);
            }
        }

        int sum = 0;
        while(!points.empty()) {
            sum += points.top(); points.pop();
        }
        return sum;
    }
};