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
    long long last = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        bool left = isValidBST(root->left);

        if(root->val <= last) return false;
        last = root->val;

        bool right =  isValidBST(root->right);

        return left && right;
    }
};