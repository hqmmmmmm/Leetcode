class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &used)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        unordered_set<int> st;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i])     // 先排除这个数是否已经加入path了
                continue;

            // 消除同一层中的重复数字，只枚举第重复数字中第一个出现的数字
            if(st.count(nums[i]))     
                continue;
            else 
                st.insert(nums[i])

            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};