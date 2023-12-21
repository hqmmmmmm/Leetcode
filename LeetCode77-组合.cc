class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }

    void dfs(int startIndex, int n, int k)
    {
        if(k == path.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= (n + 1 - (k - path.size())); ++i)
        {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }
};