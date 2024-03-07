class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
            f[i][j]: 从前i个硬币中选，总金额等于j的组合数
                不选第i个硬币： f[i -1][j]
                选第i个硬币：   f[i][j - coins[i]]
        */

        int n = coins.size(), m = amount;
        int f[310][5010] = {0};

        f[0][0] = 1;  // 从前i个硬币选，总金额等于0的组合数应当为1，不然后面的状态都是0了
        for(int i = 1; i <= n; ++i)
        {
            // 注意这里j从0开始遍历，因为f[0][0], f[1][0], f[2][0]...都要为0,也可以在上面跟f[0][0]一起赋值为0
            for(int j = 0; j <= m; ++j)  
            {
                f[i][j] = f[i - 1][j];
                if(j >= coins[i - 1])
                    f[i][j] += f[i][j - coins[i - 1]];
            }
        }
        
        return f[n][m];
    }
};