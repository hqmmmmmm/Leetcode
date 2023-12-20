class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<int> path; 
    vector<int> st;
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        path = vector<int>(n, 0);
        st = vector<int>(n, 0);
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int> &nums)
    {
        if(u == n)
        {
            res.push_back(path);
            return ;
        }

        for(int i = 0; i < n; ++i)
        {
            if(!st[i])
            {
                st[i] = 1;
                path[u] = nums[i];
                dfs(u + 1, nums);
                st[i] = 0;
            }
        }
    }
};