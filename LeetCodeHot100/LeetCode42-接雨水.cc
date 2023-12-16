class Solution {
public:
    int trap(vector<int>& height) {
        // // 双指针法
        // int i = 0, j = height.size() - 1;
        // int leftmax = 0, rightmax = 0;
        // int ans = 0;

        // while(i <= j)
        // {
        //     if(leftmax <= rightmax)  // 左右最大值更小的
        //     {
        //         leftmax = max(leftmax, height[i]); // 防止leftmax比height小
        //         ans += leftmax - height[i++];
        //     }
        //     else
        //     {
        //         rightmax = max(rightmax, height[j]);
        //         ans += rightmax - height[j--];
        //     }
        // }

        // return ans;




        // 单调栈
        // 简单来说就是当前柱子如果小于等于栈顶元素，说明形不成凹槽，则将当前柱子入栈；
        // 反之若当前柱子大于栈顶元素，说明形成了凹槽，于是将栈中小于当前柱子的元素pop出来，
        // 将凹槽的大小累加到结果中。

        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < height.size(); ++i) // 枚举每个柱子
        {
            while(!stk.empty() && height[stk.top()] < height[i]) // 栈顶小于当前柱子，可以统计栈顶的那个柱子上的雨水了
            {
                // 去除栈顶元素
                int cur = stk.top();
                stk.pop();           // 这里pop出去是可以的，下次加的时候是会*(r-l-1)的，会加上这一部分

                if(stk.empty()) break;

                int l = stk.top();
                int r = i;

                ans += (min(height[r], height[l]) - height[cur]) * (r - l - 1);
            }
            stk.push(i); // 加入当前柱子
        }
        return ans;
    }
};