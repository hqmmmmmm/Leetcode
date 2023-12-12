class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        if(!heights.size() || !limit) return {};

        vector<int> ans;
        deque<int> win;

        for(int i = 0; i < limit; ++i)  // 先构建一个窗口
        {
            while(!win.empty() && win.back() < heights[i])  // 保证单调性，去除尾部小的元素
                win.pop_back();
            win.push_back(heights[i]);
        }
        ans.push_back(win.front());

        for(int i = limit; i < heights.size(); ++i)
        {
            if(win.front() == heights[i - limit])   // 如果队列头部是要删除的元素，直接删除
                win.pop_front();

            while(!win.empty() && win.back() < heights[i]) // 保证单调性，去除尾部小的元素
                win.pop_back();
            win.push_back(heights[i]);
            
            ans.push_back(win.front());
        }
        return ans;
    }
};