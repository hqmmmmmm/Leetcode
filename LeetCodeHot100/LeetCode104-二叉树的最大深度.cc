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
    int res = 0;
    int maxDepth(TreeNode* root) {
        // dfs
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int depth)
    {
        if(root == nullptr)
            return;
        res = max(res, ++depth);
        
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
};