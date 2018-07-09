typedef struct{
    string expr;
    double value;
} Result;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        _max.clear();
        _min.clear();

        Result result = GetMaxDivision(nums, 0, nums.size()-1);
        return result.expr;
    }
    // 返回当区间nums[start:end]达到最大值时的表达式和结果
    Result GetMaxDivision(vector<int>& nums, int start, int end) {
        Result ret;
        int n = end - start + 1;
        // 使用缓存
        if(getMax(start, end, ret)) return ret;
        //cout << "max" << " [" << start << "," << end << "]" << endl;
        if(n == 1) { // 只有一个元素
            ret.value = 1.0 * nums[start];
            ret.expr = to_string(nums[start]);
            setMax(start, end, ret);
            //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
            return ret;
        }
        if(n == 2) { // 只有2个元素
            ret.value = 1.0 * nums[start] / nums[end];
            ret.expr = to_string(nums[start]) + "/" + to_string(nums[end]);
            setMax(start, end, ret);
            //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
            return ret;
        }
        double maxValue = -1.0;
        string maxExpr;
        for(int i = 0; i < n-1; i++) {
            Result leftResult = GetMaxDivision(nums, start+0, start+i);
            Result rightResult = GetMinDivision(nums, start+i+1, start+n-1);
            if((leftResult.value / rightResult.value) > maxValue) {
                maxValue = leftResult.value / rightResult.value;
                maxExpr = leftResult.expr + "/";
                if(n-(i+1) >= 2) { // 当右边的num个数>=2
                    maxExpr += "(" + rightResult.expr + ")";
                } else {
                    maxExpr += rightResult.expr;
                }
            }
        }
        ret.value = maxValue;
        ret.expr = maxExpr;
        setMax(start, end, ret);
        //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
        return ret;
    }
    // 返回当区间nums[start:end]达到最小值时的表达式和结果
    Result GetMinDivision(vector<int>& nums, int start, int end) {
        Result ret;
        int n = end - start + 1;
        if(getMin(start, end, ret)) return ret;
        //cout << "min" << " [" << start << "," << end << "]" << endl;
        if(n == 1) {
            ret.value = 1.0 * nums[start];
            ret.expr = to_string(nums[start]);
            setMin(start, end, ret);
            //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
            return ret;
        }
        if(n == 2) {
            ret.value = 1.0 * nums[start] / nums[end];
            ret.expr = to_string(nums[start]) + "/" + to_string(nums[end]);
            setMin(start, end, ret);
            //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
            return ret;
        }
        double minValue = 1E+37;
        string minExpr;
        for(int i = 0; i < n-1; i++) {
            Result leftResult = GetMinDivision(nums, start+0, start+i);
            Result rightResult = GetMaxDivision(nums, start+i+1, start+n-1);
            if((leftResult.value / rightResult.value) < minValue) {
                minValue = leftResult.value / rightResult.value;
                minExpr = leftResult.expr + "/";
                if(n-(i+1) >= 2) { // 当右边的num个数>=2
                    minExpr += "(" + rightResult.expr + ")";
                } else {
                    minExpr += rightResult.expr;
                }
            }
        }
        ret.value = minValue;
        ret.expr = minExpr;
        setMin(start, end, ret);
        //cout << "Ret: " << ret.expr << " = " << ret.value << endl;
        return ret;
    }
private:
    bool setMax(int start, int end, const Result& result) {
        string key = getKey(start, end);
        _max[key] = result;
        return true;
    }
    bool getMax(int start, int end, Result& result) {
        string key = getKey(start, end);
        auto it = _max.begin();
        if((it = _max.find(key)) != _max.end()) {
            result = it->second;
            return true;
        }
        return false;
    }
    bool setMin(int start, int end, const Result& result) {
        string key = getKey(start, end);
        _min[key] = result;
        return true;
    }
    bool getMin(int start, int end, Result& result) {
        string key = getKey(start, end);
        auto it = _min.begin();
        if((it = _min.find(key)) != _min.end()) {
            result = it->second;
            return true;
        }
        return false;
    }
    string getKey(int start, int end) {
        return to_string(start) + "$" + to_string(end);
    }

    map<string, Result> _min;
    map<string, Result> _max;
};