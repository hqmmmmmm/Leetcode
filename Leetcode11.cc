// Leetcode11.盛最多水的容器
/*
    双指针，左指针初始指向第一个元素，右指针指向最后一个元素，
    计算此时容器大小，取max，
    
    移动较小的指针，（为什么要移动较小的指针？木桶效应：容纳的水量是由两个指针指向的数字中较小值决定的
    如果移动较大的指针，首先移动后容器的高一定小于等于当前的高，并且底减小了1.
    所以移动较小的指针。

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;

        while(left < right)
        {
            ans = max((right - left) * min(height[right], height[left]), ans);
            if(height[left] < height[right])
                left++;
            else 
                right--;
        }
        return ans;
    }
};