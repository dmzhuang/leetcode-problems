class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int length = 0, maxLength = 0, n = seats.size();
        bool isFirst = true;
        for(int i = 0; i < n; i++) {
            if(!seats[i]) length++;
            else if(length) {
                if(isFirst) {
                    isFirst = false;
                    if(seats[0]) {
                        length = (length + 1) / 2;
                    }
                }
                length = (length + 1)/2;
                if(length > maxLength)
                    maxLength = length;
                length = 0;
            }
        }
        if(length && length > maxLength) {
            maxLength = length;
        }
        return maxLength;
    }
};