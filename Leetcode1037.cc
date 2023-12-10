class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // y2 - y1 / x2 - x1 != y3 - y1 / x3 - x1 斜率不相等即可, 
        // 因为可能是整数除法，可能丢失小数位，将这个除法转化为乘法即可。
        int p1 = (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
        int p2 = (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);

        return p1 != p2;
    }
};