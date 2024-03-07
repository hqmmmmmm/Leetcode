class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
            f[i][j]  表示以第1~i个元素结尾的元素排列总和等于target的排列种数。
                状态划分：以第1~i-1个元素结尾    f[i - 1][j]
                         以第i个元素结尾        f[n][j - nums[i - 1]]   
                                               确定了排列最后一个元素是第i个，前面的元素可以以任意元素结尾 
        */
        int f[210][1010] = {0};
        f[0][0] = 1;   // 实际应该是f[i][0]都等于1,延迟到在下面的循环中设置了

        int n = nums.size(), m = target;
        for(int j = 0; j <= m; ++j) // 注意这里要先遍历j，因为下面状态转移方程中的下标有些特殊，具体画个矩阵图观察状态转移就行了。
        {
            for(int i = 1; i <= n; ++i)
            {
                f[i][j] = f[i - 1][j];
                // 中间某些状态的值可能大于INT_MAX，这里可以不用算，直接跳过；或者也可以直接用unsignd long long类型数组
                // 因为题目说了确保结果小于INT_MAX，说明最终的状态不可能由这个中间状态转移而来
                if(j >= nums[i - 1] && f[i][j] < INT_MAX - f[n][j - nums[i - 1]])  // 一定要注意这里是nums[i - 1]
                    f[i][j] += f[n][j - nums[i - 1]];   
            }
        }

        return f[n][m];
    }
};