class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, candidates, target);
        return res;
    }

    void dfs(int startIndex, int sum, vector<int>& candidates, int target)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        if(sum > target || startIndex >= candidates.size())
            return;

        // 这种dfs相当于在枚举path的当前位置选取哪一个数字！！
        // 之前我理解的那种dfs相当于在枚举待选集合中的某个数字选还是不选。
        for(int i = startIndex; i < candidates.size(); ++i)  
        {
            path.push_back(candidates[i]);
            dfs(i, sum + candidates[i], candidates, target);
            path.pop_back();
        }
    }
};