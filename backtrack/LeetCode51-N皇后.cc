class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> dg(2 * n, false);
        vector<bool> udg(2 * n, false);
        for(int i = 0; i < n; ++i)
            path.emplace_back(n, '.');

        dfs(0, n, col, dg, udg);
        return res;
    }

    void dfs(int x, int n, vector<bool> col, vector<bool> dg, vector<bool> udg)
    {
        if(x == n)
        {
            res.push_back(path);
            return;
        }

        for(int y = 0; y < n; ++y)
        {
            if(!col[y] && !dg[y - x + n] && !udg[y + x])
            {
                col[y] = dg[y - x + n] = udg[y + x] = true;
                path[x][y] = 'Q';
                dfs(x + 1, n, col, dg, udg);
                col[y] = dg[y - x + n] = udg[y + x] = false;
                path[x][y] = '.';
            }
        }
    }
};