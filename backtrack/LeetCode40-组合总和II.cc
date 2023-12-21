class Solution {
public: 
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 让相同的元素挨在一起
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

        if(startIndex >= candidates.size() || sum > target)
            return;

        for(int i = startIndex; i < candidates.size(); ++i)
        {
            // 同一层使用过的节点不再使用
            if(i > startIndex && candidates[i] == candidates[i - 1])  
                continue;

            path.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i], candidates, target);
            path.pop_back();
        }
    }
};