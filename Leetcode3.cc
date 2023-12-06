// Leetcode3.无重复字符的最长子串
// 滑动窗口思路：求最长：
// 左右指针维护一个窗口，窗口满足要求时，右指针右移；窗口不满足要求时，左指针左移。
// 我下面这个while+if方法求最短窗口时，有些时候需要注意，最后右指针离开窗口后可能还有最小值没有更新。
// 网上有while+whie的模板。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> h;
        int ans = 0;
        int i = 0, j = 0;
        while(j < n)
        {
            if(!h.count(s[j])) 
            {
                h.insert(s[j]);
                ++j;
                ans = max(ans, j - i);
            }
            else
            {
                h.erase(s[i]);
                ++i;
            }
        }

        return ans;
    }
};