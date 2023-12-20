class Solution {
public:
    bool res = false;
    vector<vector<int>> st;

    bool exist(vector<vector<char>>& board, string word) {

        if(board.size() == 1 && board[0].size() == 1)
            if(word.size() == 1 && word[0] == board[0][0])
                return true;

        for(int i = 0; i < board.size(); ++i)
        {
            vector<int> tmp;
            for(int j = 0; j < board[i].size(); ++j)
                tmp.push_back(0);
            st.push_back(tmp);
        }

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
            {
                st[i][j] = 1;
                dfs(0, i, j, board, word);
                st[i][j] = 0;
            }
        
        return res;
    }


    void dfs(int u, int i, int j, vector<vector<char>> &board, string word)
    {
        if(res) return;

        if(board[i][j] == word[u])
        {
            if(u == word.size() - 1)
            {
                res = true;
                return;
            }
            if(i - 1 >= 0 && !st[i - 1][j])
            {
                st[i - 1][j] = 1;
                dfs(u + 1, i - 1, j, board, word);
                st[i - 1][j] = 0;
            }
            if(i + 1 < board.size() && !st[i + 1][j])
            {
                st[i + 1][j] = 1;
                dfs(u + 1, i + 1, j, board, word);
                st[i + 1][j] = 0;
            }
            if(j - 1 >= 0 && !st[i][j - 1])
            {
                st[i][j - 1] = 1;
                dfs(u + 1, i, j - 1, board, word);
                st[i][j - 1] = 0;
            }
            if(j + 1 < board[0].size() && !st[i][j + 1])
            {
                st[i][j + 1] = 1;
                dfs(u + 1, i, j + 1, board, word);
                st[i][j + 1] = 0;
            }
        }
        else
            return;

    }
};