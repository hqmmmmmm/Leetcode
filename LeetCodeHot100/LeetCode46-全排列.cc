class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used;

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), 0);
        dfs(nums);
        return res;
    }

    void dfs(vector<int> &nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(!used[i])
            {
                path.push_back(nums[i]);
                used[i] = 1;
                dfs(nums);
                path.pop_back();
                used[i] = 0;
            }
        }
    }
};