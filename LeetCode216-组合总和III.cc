// 每个数字选1次，可根据每个数字选还是不选来进行回溯，每次递归枚举一个数字，属于组合问题
// 如果是排列问题，需要一个记录是否选取的数组st；组合问题不需要
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int n;
    int k;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n, this->k = k;
        if(k > 9 || n > 45)
            return res;

        dfs(1, 0, 0);
        return res;
    }

    void dfs(int u, int s, int cnt)
    {
        if(s == n)
        {
            if(cnt == k)
                res.push_back(path);

            return;
        }
        if(cnt == k + 1 || s > n || u == 10) return;

        path.push_back(u);
        dfs(u + 1, s + u, cnt + 1);
        path.pop_back();

        dfs(u + 1, s, cnt);
    }
};