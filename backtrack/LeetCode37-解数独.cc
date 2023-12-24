class Solution {
public:
    int getIndex(int x, int y)
    {
        return (x / 3) * 3 + y / 3;
    }
    
    bool row[9][10], col[9][10], block[9][10];  // 记录元素是否已经被用过

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
            }
        }

        dfs(board);
    }

    bool dfs(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1'; k <= '9'; ++k)
                    {
                        if(!row[i][k - '0'] && !col[j][k - '0'] && !block[getIndex(i, j)][k - '0'])
                        {
                            row[i][k - '0'] = col[j][k - '0'] = block[getIndex(i, j)][k - '0'] = true;
                            board[i][j] = k;
                            if(dfs(board)) return true;  // 放置k可行，返回true
                            row[i][k - '0'] = col[j][k - '0'] = block[getIndex(i, j)][k - '0'] = false;
                            board[i][j] = '.';
                        }
                    }
                    return false;  // 在这个位置(i, j)放1~9任何数字都不可行
                }
            }
        }
        return true;   // 双层for循环board中没有=='.'的，所有元素已经放置完毕。
    }
};
