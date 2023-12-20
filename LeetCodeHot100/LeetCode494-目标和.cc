class Solution {
public:
    int res = 0;
    int target;

    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        dfs(0, 0, nums);
        return res;
    }

    void dfs(int u, int s, vector<int> &nums)
    {
        if(u == nums.size())   // 必须要在每个数前面都加符号才能算一种可行方案
        {
            if(s == target)
                res++;
            return;
        }

        dfs(u + 1, s + nums[u], nums);

        dfs(u + 1, s - nums[u], nums);
    }

};