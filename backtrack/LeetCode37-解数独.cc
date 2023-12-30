class Solution {
public:
    int getIndex(int x, int y)
    {
        return (x / 3) * 3 + y / 3;
    }
    
    bool row[9][10], col[9][10], block[9][10];  // 记录元素是否已经被用过
    bool res = false;
    vector<pair<int, int>> spaces;   // 存储board中.的位置，这些位置需要放数

    void solveSudoku(vector<vector<char>>& board) {   
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 10; ++j)     
                row[i][j] = col[i][j] = block[i][j] = false;

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                char k = board[i][j];
                if(k != '.')
                    row[i][k - '0'] = col[j][k - '0'] = block[getIndex(i, j)][k - '0'] = true;
                else
                    spaces.emplace_back(i, j); // 初始化spaces
            }
        }

        dfs(0, board);
    }

    void dfs(int pos, vector<vector<char>>& board)
    {
        if(pos == spaces.size())
        {
            res = true;
            return;
        }
        
        auto [i, j] = spaces[pos];
        
        for(char k = '1'; k <= '9'; ++k)
        {
            if(res) return;

            if(!row[i][k - '0'] && !col[j][k - '0'] && !block[getIndex(i, j)][k - '0'])
            {
                row[i][k - '0'] = col[j][k - '0'] = block[getIndex(i, j)][k - '0'] = true;
                board[i][j] = k;
                dfs(pos + 1, board);
                row[i][k - '0'] = col[j][k - '0'] = block[getIndex(i, j)][k - '0'] = false;
                //board[i][j] = '.';      // 为什么这里不用复原？  
                // 我的理解：1、如果正确答案在另一个叶子节点，它一定会对board中所有.位置重新赋值，不需要复原board[i][j]
                //          2、如果复原board[i][j]，回溯后得不到答案（画个树形图比较好理解）
            }
        }
    }
};

