// Leetcode209.长度最小的子数组
// 使用左右两个指针维护一个滑动窗口即可。
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;             // 左右指针维护一个窗口保存子数组
        int cur = 0, ans = INT_MAX;   // cur当前窗口中元素和，ans答案

        while(j < n || cur >= target)  
        {
            if(cur >= target)      // 如果当前窗口中元素和大于target，左指针右移
            {
                ans = min(ans, j - i);
                cur -= nums[i++];
            }
            else if(cur < target)  // 如果当前窗口中元素和小于target，右指针右移
            {
                cur += nums[j++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
