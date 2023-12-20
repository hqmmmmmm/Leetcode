class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int target;
    int n;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->n = candidates.size(), this->target = target;
        dfs(0, 0, candidates);
        return res;
    }

    void dfs(int u, int s, vector<int> &nums)
    {
        if(s == target) 
        {
            res.push_back(path);
            return ;
        }
        if(u == n || s > target) 
            return;

        path.push_back(nums[u]);
        dfs(u, s + nums[u], nums);
        path.pop_back();

        dfs(u + 1, s, nums);
    }
};

/*





*/