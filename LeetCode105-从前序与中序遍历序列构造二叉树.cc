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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); ++i)
            dict[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dict;

    TreeNode *recur(int root, int left, int right)
    {
        if(left > right) return nullptr;     // 递归终止
        TreeNode *node = new TreeNode(preorder[root]);
        int i = dict[preorder[root]];
        node->left = recur(root + 1, left, i - 1);
        node->right = recur(root + 1 + i - left, i + 1, right);
        return node;
    }
};