class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == '1')  
                {
                    res++;
                    dfs(i, j, grid);
                }
            }
        return res;
    }

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if(grid[i][j] == '0')
            return;
        else
            grid[i][j] = '0';     // 将连在一起的1都修改为0，这样一个岛屿一个1，统计1的个数即可

        if(i - 1 >= 0)                  dfs(i - 1, j, grid);
        if(i + 1 < grid.size())         dfs(i + 1, j, grid);
        if(j - 1 >= 0)                  dfs(i, j - 1, grid);
        if(j + 1 < grid[0].size())      dfs(i, j + 1, grid);
    }

};