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
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return res;
    }

    int dfs(TreeNode *root) // 计算子树长度
    {
        if(root == nullptr)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    void f(TreeNode *root)
    {
        if(root == nullptr)  return;

        int tmp = dfs(root->left) + dfs(root->right);
        res = max(res, tmp);

        f(root->left), f(root->right);
    }
};