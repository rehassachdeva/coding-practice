// Linearising / Linear complete binary tree

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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        tree.emplace_back(root);
        for (int i=0; i<tree.size(); i++)
        {
            if (tree[i]->left)
                tree.emplace_back(tree[i]->left);
            if (tree[i]->right)
                tree.emplace_back(tree[i]->right);
        }
    }
    
    int insert(int v) {
        int n=tree.size();
        tree.emplace_back(new TreeNode(v));
        int par=(n-1)/2;
        if (n%2==0)
            tree[par]->right = tree[n];
        else
            tree[par]->left = tree[n];
        return tree[par]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
    vector<TreeNode*> tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */