// 二分查找
// 查找target，若找到，返回其index；若没有，返回target该插入的位置

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid; // 闭区间[low, high]

        while(low < high) {         // 闭区间内至少有两个元素
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                low = mid+1;
            else
                high = mid;
        }
        if(low == high) {   // 当nums.size()=1，或从上面的while出来：一定有low=high，也就是闭区间只有一个元素
            if(nums[low] >= target) return low;
            return low + 1;
        }
        return 0;   // 这是针对nums为空的情况
    }
};