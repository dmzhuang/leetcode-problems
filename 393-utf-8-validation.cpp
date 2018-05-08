// A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

// For 1-byte character, the first bit is a 0, followed by its unicode code.
// For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
// This is how the UTF-8 encoding would work:

//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

// Note:
// The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

// Example 1:

// data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

// Return true.
// It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
// Example 2:

// data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

// Return false.
// The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
// The next byte is a continuation byte which starts with 10 and that's correct.
// But the second continuation byte does not start with 10, so it is invalid.


class Solution {
private:
    int getFollwingBytesNum(int num) {
        int value = num & 0xff;
        if(value < 128)
            return 0;
        if(value < 128+64)
            return -1;
        if(value < 128+64+32)
            return 1;
        if(value < 128+64+32+16)
            return 2;
        if(value < 128+64+32+16+8)
            return 3;
        return -1;
    }
    bool startsWith10(int num) {
        int value = num & 0xff;
        return value >= 128 && value < 128+64;
    }
public:
    bool validUtf8(vector<int>& data) {
        int size = data.size();
        int n = 0;
        bool ret_val = true;

        for(int i = 0; i < size; i++) {
            if(n == 0) {
                n = getFollwingBytesNum(data[i]);
                if(n < 0) {
                    ret_val = false;
                    break;
                }
            }else {
                if(startsWith10(data[i])) {
                    n--;
                }else {
                    ret_val = false;
                    break;
                }
            }
        }
        if(n > 0)
            ret_val = false;
        return ret_val;
    }
};