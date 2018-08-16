class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.reserve(max(nums1.size(), nums2.size()));
        quick_sort(nums1, 0, nums1.size()-1);
        quick_sort(nums2, 0, nums2.size()-1);

        int m = nums1.size(), n = nums2.size();
        for(int i = 0, j = 0; i < m && j < n; ) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ++i, ++j;
            }
            else if(nums1[i] > nums2[j])
                ++j;
            else if(nums1[i] < nums2[j])
                ++i;
        }
        ans.shrink_to_fit();
        return ans;
    }
    void quick_sort(vector<int>& nums, int start, int end) {
        if(end > start) {
            int p = partition(nums, start, end);
            quick_sort(nums, start, p-1);
            quick_sort(nums, p+1, end);
        }
    }
private:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end], last_small = start - 1;
        for(int j = start; j < end; j++)
            if(nums[j] <= pivot) {
                last_small += 1;
                swap(nums, last_small, j);
            }
        swap(nums, last_small+1, end);
        return last_small + 1;
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};