class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int i = 0, j = 1;
        while(j < candidates.size())
        {
            if(candidates[j] == candidates[j - 1])
                candidates[i++] = candidates[j];
            ++j; 
        }
        candidates.resize(i);

        dfs(0, 0, candidates, target);
    }   

    void dfs(int u, int s, vector<int>& candidates, int target)
    {
        // 第
    }
};