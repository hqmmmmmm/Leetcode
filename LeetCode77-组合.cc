class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        path.resize(k);
        dfs(1, 0, k, n);

        return res;
    }


    void dfs(int u, int v, int k, int n)
    {
        if(v == k)
        {
            res.push_back(path);
            return ;
        }
        if(u == n + 1)
            return;
        if(v + n - u + 1 < k)   // 剪枝，此时即使u~n全部被选中也无法构造出长度为k的序列，直接return
            return;

        path[v] = u;
        dfs(u + 1, v + 1, k, n);
        
        dfs(u + 1, v, k, n);
    }
};