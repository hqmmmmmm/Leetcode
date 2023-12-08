class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> win;

        // 未形成窗口
        for(int i = 0; i < k; ++i)
        {
            while(!win.empty() && win.back() < nums[i])
                win.pop_back();
            win.push_back(nums[i]);
        }
        ans.push_back(win.front());

        // 形成窗口后
        for(int i = k; i < nums.size(); ++i)
        {
            if(nums[i - k] == win.front())
                win.pop_front();
            while(!win.empty() && win.back() < nums[i])
                win.pop_back();
            win.push_back(nums[i]);
            
            ans.push_back(win.front());
        }
        // 未形成窗口和形成窗口后，可以合并到同一个for循环中，不过要多及格if判断
        return ans;
            
    }
};