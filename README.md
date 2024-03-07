# Leetcode刷题仓库

12.8

[Leetcode1222.可以攻击国王的皇后](https://leetcode.cn/problems/queens-that-can-attack-the-king/description/)
    
[LCR 167. 招式拆解 I](https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/description/) 即无重复的最长子串

[Leetcode239.滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)



12.12

[LCR183.望远镜中最高的海拔](https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/description/)

[Leetcode1438.绝对差不超过限制的最长连续子数组](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

[LeetCode20.有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)

[LeetCode42.接雨水](https://leetcode.cn/problems/trapping-rain-water/)

[LeetCode155.最小栈](https://leetcode.cn/problems/min-stack/description/)

[LeetCode287.寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/description/)



动态规划：
- 注意dp数组习惯于从1开始，但是注意对应原来元素数组的下标就要-1！！！！
- 注意二层循环的那个j是从0开始遍历还是1开始遍历是不一定的！！要仔细想想！

完全背包:    f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]]+ w[i])
            // 因为第i个物品可以取多次，所以i不用变为i-1！！！