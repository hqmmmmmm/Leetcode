class Solution {
public:
    int left, right;
    string path;
    vector<string> res;
    int n;

    vector<string> generateParenthesis(int n) {
        this->n = n;
        left = right = n;
        path.resize(2 * n, ' ');
        dfs(0);
        return res;
    }

    void dfs(int u)
    {
        if(u == 2 * n)
        {
            res.push_back(path);
            return;
        }

        if(left)
        {
            left--;
            path[u] = '(';
            dfs(u + 1);
            left++;
        }

        if(left < right)
        {
            right--;
            path[u] = ')';
            dfs(u + 1);
            right++;
        }
    }
};