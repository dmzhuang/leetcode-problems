class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), p = 0, q = n-1, length = n; // p的左侧全不为val，q的右侧全为val

        while(p <= q) {
            int tp = p, tq = q;
            while(p < n && nums[p] != val) p++;
            while(q >= 0 && nums[q] == val) q--, length--;

            if(p >= n || q < 0 || p > q) {
                break;
            }

            int temp = nums[p]; nums[p] = nums[q]; nums[q] = temp;
            p++, q--, length--;
        }
        return length;
    }
};