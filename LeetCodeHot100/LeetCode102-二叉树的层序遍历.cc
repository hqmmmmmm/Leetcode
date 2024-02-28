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
    vector<vector<int>> res;
    vector<int> cur;
    queue<TreeNode *> q;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return res;
        q.push(root);

        while(q.size())
        {
            int cnt = q.size();
            while(cnt--)
            {
                auto tmp = q.front();
                cur.push_back(tmp->val);
                q.pop();

                if(tmp->left)  q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            
            res.push_back(cur);
            cur.resize(0);
        }

        return res;
    }
};