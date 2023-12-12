class Solution {
public:  // 跟链表找环问题一样
    int findDuplicate(vector<int>& nums) {
        // 初始情况下，快指针从0开始跳两步，慢指针从0开始跳一步
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;   // 从起点出发
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};