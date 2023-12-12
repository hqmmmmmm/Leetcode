class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 方法一：两个单调队列分别记录最大值和最小值
        deque<int> minq, maxq;
        int i = 0, j = 0, ans = 0;
        while(j < nums.size())
        {
            while(!minq.empty() && minq.back() > nums[j])
                minq.pop_back();
            minq.push_back(nums[j]);

            while(!maxq.empty() && maxq.back() < nums[j])
                maxq.pop_back();
            maxq.push_back(nums[j]);

            ++j;

            while(!minq.empty() && !maxq.empty() &&
                    maxq.front() - minq.front() > limit)
            {
                if(nums[i] == minq.front())
                    minq.pop_front();
                if(nums[i] == maxq.front())
                    maxq.pop_front();
                ++i;
            }
            ans = max(j - i, ans);
        }
        return ans;
        // 方法二：直接用有序集合multiset
    }
};