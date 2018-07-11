/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    using long_t = long int;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<long_t, int> freq;
        frequentTreeSum(root, freq);

        vector<int> ans;
        getMaxFrequent(freq, ans);

        return ans;
    }
private:
    void getMaxFrequent(map<long_t, int>& freq, vector<int>& ans) {
        if(freq.size() == 0) return;

        long_t maxFreq = (freq.begin())->second;
        for(auto it = freq.begin(); it != freq.end(); it++)
            if(it->second > maxFreq)
                maxFreq = it->second;

        for(auto it = freq.begin(); it != freq.end(); it++)
            if(it->second == maxFreq)
                ans.push_back(it->first);
    }

    int frequentTreeSum(TreeNode* root, map<long_t, int>& freq) {
        if(!root) return 0;

        long_t f = 0;
        f += frequentTreeSum(root->left, freq);
        f += frequentTreeSum(root->right, freq);
        f += root->val;

        auto it = freq.begin();
        if((it = freq.find(f)) == freq.end())
            freq[f] = 0;
        freq[f]++;

        return f;
    }
};