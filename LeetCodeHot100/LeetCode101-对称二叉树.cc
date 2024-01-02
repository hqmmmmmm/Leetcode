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
    bool isSymmetric(TreeNode* root) {
        return f(root->left, root->right);
    }

    bool f(TreeNode *left, TreeNode *right)
    {
        if(left == nullptr && right == nullptr)
            return true;

        if(left && right)
        {
            if(left->val == right->val)
                return f(left->left, right->right) && f(left->right, right->left);
            else 
                return false;
        }
        else 
            return false;
    }
};