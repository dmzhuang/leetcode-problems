class Solution {
public:
    int rotatedDigits(int N) {
        int totalCount = 0;
        MAXN = N;

        for(int i = 1; i <= 9; i++) {
            if(i > MAXN)
                break;
            if(can_rotate(i))
                totalCount += Traversal(i, is_different(i));
        }
        return totalCount;
    }
private:
    int Traversal(int n, bool isDiff) {
        int count = isDiff ? 1 : 0;
        for(int i = 0; i <= 9; i++) {
            int child = n * 10 + i;
            if(child > MAXN)
                break;
            if(can_rotate(i))
                count += Traversal(child, isDiff | is_different(i));
        }
        return count;
    }
    bool can_rotate(int n) {
        return (n != 3) && (n != 4) && (n != 7);
    }
    bool is_different(int n) {
        return (n == 2) || (n == 5) || (n == 6) || (n == 9);
    }
    int MAXN;
};