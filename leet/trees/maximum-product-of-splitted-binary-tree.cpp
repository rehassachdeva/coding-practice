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
    
    long long int getsum(TreeNode* root)
    {
        if (!root)
            return 0;
        
        return root->val + getsum(root->left) + getsum(root->right);
    }
    
    long long int dfs(TreeNode* root, long long int& tot, long long int& ans)
    {
        if (!root)
            return 0;
        
        long long int cur = root->val + dfs(root->left, tot, ans) + dfs(root->right, tot, ans);
        
        ans = max(ans, ((tot - cur) * cur));
        
        return cur;
    }
    
    int maxProduct(TreeNode* root) {
        
        long long int tot = getsum(root);
        long long int ans=0;
        
        dfs(root, tot, ans);
        
        return ans % mod;
    }
    
    static const int mod = 1e9+7;                 

};