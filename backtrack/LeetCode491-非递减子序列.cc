class Solution {
public:
    vector<vector<int>> res;
    vector<int>path;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int startIndex, vector<int> &nums)
    {
        if(path.size() >= 2)
            res.push_back(path);
        if(startIndex == nums.size())
            return;
        
        unordered_set<int> st;
        for(int i = startIndex; i < nums.size(); ++i)
        {
            if(st.count(nums[i]))   // 同一层相同的数字只用一次（用第一个） 
                continue;
            else
                st.insert(nums[i]);
            // 其实子集II那题的去重和这题差不多，只不过那题比较特殊，重复的数字都是相邻的，这题更普遍

            if(path.empty() || path.back() <= nums[i])
            {
                path.push_back(nums[i]);
                dfs(i + 1, nums);
                path.pop_back();
            }
        }
    }
};