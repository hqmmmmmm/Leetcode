class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 0, k, n);
        return res;
    }
    void dfs(int startIndex, int s, int k, int n)
    {
        if(s > n) return;
        if(path.size() == k)
        {
            if(s == n) res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= 9; ++i)
        {
            path.push_back(i);
            dfs(i + 1, s + i, k, n);
            path.pop_back();
        }
    }
};