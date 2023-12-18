class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
            return v1[0] < v2[0];
        });

        vector<vector<int>> res;
        int right = intervals[0][1], left = intervals[0][0];
        for(auto &v : intervals)
        {
            if(v[0] <= right)
                right = max(right, v[1]); // 注意，比如[1, 4], [2, 3]这种可能后面的区间被前面的区间完全包含，所以right要取较大值
            else
            {
                res.push_back({left, right});
                left = v[0], right = v[1];
            }
        }
        res.push_back({left, right});

        return res;
    }
};