
int rating[26] = {0};

void SetRating(const string& S) {
    memset(rating, 26, sizeof(rating));
    int i = 1;
    for(char c : S) {
        rating[c - 'a'] = i++;
    }
}

bool cmp(char lhs, char rhs) {
    return rating[lhs-'a'] < rating[rhs-'a'];
}

class Solution {
public:
    string customSortString(string S, string T) {
        SetRating(S);

        sort(T.begin(), T.end(), cmp);
        return T;
    }
};
