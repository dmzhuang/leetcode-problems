class Solution:
    def sortColors(self, data):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        start = 0
        end = len(data) - 1
        last_zero = start - 1
        first_two = end + 1
        j = start
        while j < first_two:
            if data[j] == 1:
                j += 1
                continue
            if data[j] == 0:
                last_zero += 1
                self.swap(data, last_zero, j)
                j += 1
                continue
            if data[j] == 2:
                first_two -= 1
                self.swap(data, first_two, j)
                continue

    def swap(self, data, i, j):
        temp = data[i]
        data[i] = data[j]
        data[j] = temp


