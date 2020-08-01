// pairs of nodes at depth without lca

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, unordered_map<int, int>> recur(TreeNode* root, int distance)
    {
        if (!root)
            return {0, {}};
        if (!root->left and !root->right)
            return {0, {{0,1}}};
        auto l=recur(root->left, distance);
        auto r=recur(root->right, distance);
        int ret = l.first+r.first;
        for (auto& [dl, ndl] : l.second)
        {
            for (auto& [dr, ndr] : r.second)
            {
                if (dl+dr+2 <= distance)
                    ret += ndl*ndr;
            }
        }
        unordered_map<int, int> cnt;
        for (auto& [dl, ndl] : l.second)
            cnt[dl+1]+=ndl;
        for (auto& [dr, ndr] : r.second)
            cnt[dr+1]+=ndr;
        return {ret, cnt};
    }
    int countPairs(TreeNode* root, int distance) {
        return recur(root, distance).first;
    }
};