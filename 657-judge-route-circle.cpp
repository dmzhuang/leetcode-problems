class Solution {
public:
    using Point = struct {int x; int y;};
    bool judgeCircle(string moves) {
        Point currPos;
        currPos.x = currPos.y = 0;

        for(char c : moves) {
            switch(c) {
                case 'R': move(currPos, 0, 1);
                    break;
                case 'L': move(currPos, 0, -1);
                    break;
                case 'U': move(currPos, -1, 0);
                    break;
                case 'D': move(currPos, 1, 0);
                    break;
            }
        }
        if(currPos.x == 0 && currPos.y == 0)
            return true;
        return false;
    }
    void move(Point& pos, int x_delta, int y_delta) {
        pos.x += x_delta;
        pos.y += y_delta;
    }
};