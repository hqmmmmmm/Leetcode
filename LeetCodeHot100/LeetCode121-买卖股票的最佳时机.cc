class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = prices[0];

        for(auto &price : prices)
        {
            // 如果当前价格比较低，可能在这天买入，更新最低价格
            minPrice = min(minPrice, price);
            // 如果当前价格比较高，可能在这天卖出
            res = max(res, price - minPrice);
        }
        return res;
    }
};