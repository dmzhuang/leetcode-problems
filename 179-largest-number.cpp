class Less {
public:
    bool operator()(const int& lhs, const int& rhs) const {
        string s1 = to_string(lhs) + to_string(rhs), s2 = to_string(rhs) + to_string(lhs);
        return (s1 > s2) ? true : false;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        std::sort(begin(nums), end(nums), Less());
        for(int& i : nums) {
            ans += to_string(i);
        }
        if(!ans.empty() && ans[0] == '0') ans = "0";
        return ans;
    }
};