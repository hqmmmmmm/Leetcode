// Leetcode1222.可以攻击的皇后
/*
    模拟题。
    两种做法：1、从皇后出发（下面采用的）
        枚举每个皇后，看是否在国王的8个方向上，将8个方向通过trans函数映射为数组的8个下标，
        分别存储每个方向上距离国王最近的皇后，初始坐标均为（100，100），表示这个方向上还没有皇后。
        官方题解的做法1采用的主要是映射的方式不同，映射方式没有我写的这么长，可以参考一下。
    做法2：从国王出发
        枚举国王的8个方向，将每个方向上遇到的第一个皇后push到ans中。
        方法不错，也可以参考一下。
*/

class Solution {
public:
    int trans(int qx, int qy, int kx, int ky)
    {
        if(qx == kx && qy < ky) return 0;
        if(qx - kx == qy - ky && qx < kx && qy < ky) return 1;
        if(qx < kx && qy == ky) return 2;
        if(qx - kx == ky - qy && qx < kx && qy > ky) return 3;
        if(qx == kx && qy > ky) return 4;
        if(qx - kx == qy - ky && qx > kx && qy > ky) return 5;
        if(qx > kx && qy == ky) return 6;
        if(qx - kx == ky - qy && qx > kx && qy < ky) return 7;
        return -1;
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> h(8, {100, 100});
        for(auto &q : queens)
        {   
            int index = trans(q[0], q[1], king[0], king[1]);
            if(index == -1) continue;
            
            if(abs(q[0] - king[0]) <= abs(h[index][0] - king[0]) &&
                abs(q[1] - king[1]) <= abs(h[index][1] - king[1]))
                h[index] = {q[0], q[1]};
        }
        vector<vector<int>> ans;
        for(auto &v : h)
        {
            if(v[0] != 100)
                ans.push_back(v);
        }
        return ans;
    }
};