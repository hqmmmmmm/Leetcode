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
    TreeNode* invertTree(TreeNode* root) {
        recur(root);
        return root;
    }

    void recur(TreeNode *root)
    {
        if(root == nullptr) return;

        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        recur(root->left), recur(root->right);
    }
};