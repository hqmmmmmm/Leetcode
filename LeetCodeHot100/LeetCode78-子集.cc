class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int startIndex, vector<int>& nums)
    {
        res.push_back(path);  // 树的每个节点都要记录，
        if(startIndex == nums.size())
            return;
        
        for(int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(i + 1, nums);
            path.pop_back();
        }
    }
};