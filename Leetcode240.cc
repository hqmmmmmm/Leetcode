// Leetcode240.搜索二维矩阵II
// Z字形查找
// 没用什么特殊的算法，利用矩阵元素间的大小关系，一次性排除一列或一行


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target) 
                return true;
            else if(matrix[i][j] > target) 
                --j;
            else if(matrix[i][j] < target)
                ++i;
        }
        return false;
    }
};