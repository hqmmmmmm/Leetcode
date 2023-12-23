// 和《组合问题II》一样的方法：先排序，递归树中同一层相邻相等的结点，直接continue跳过。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }

    void dfs(int startIndex, vector<int>& nums)
    {
        res.push_back(path);
        if(startIndex == nums.size())
            return;

        unordered_set<int> st;
        for(int i = startIndex; i < nums.size(); ++i)
        {
            // 这里continue时，必须要i>startIndex，因为保证是同一层的continue，防止把同一枝干的continue了。
            // 具体画图看看
            // if(i > startIndex && nums[i] == nums[i - 1])
            //     continue;

            if(st.count(nums[i]))
                continue;
            else 
                st.insert(nums[i]);

            path.push_back(nums[i]);
            dfs(i + 1, nums);
            path.pop_back();
        }
    }
};