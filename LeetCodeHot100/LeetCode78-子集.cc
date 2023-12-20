class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int>& nums)
    {
        if(u == n)
        {
            res.push_back(path);   // 注意这里不需要将path清零，dfs中会自动恢复现场            
            return ;
        }

        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();

        dfs(u + 1, nums);
    }
};