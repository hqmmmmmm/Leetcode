// Leetcode11.盛最多水的容器
/*
    双指针，左指针初始指向第一个元素，右指针指向最后一个元素，
    计算此时容器大小，取max，
    
    移动较小的指针，（为什么要移动较小的指针？木桶效应：容纳的水量是由两个指针指向的数字中较小值决定的
    如果移动较大的指针，首先移动后容器的高一定小于等于当前的高，并且底减小了1.
    所以移动较小的指针。

    
    正确性证明：
    若暴力枚举，水槽两板围成面积 S(i,j)S(i, j)S(i,j) 的状态总数为 C(n,2)C(n, 2)C(n,2) 。

    假设状态 S(i,j)S(i, j)S(i,j) 下 h[i]<h[j]h[i] < h[j]h[i]<h[j] ，在向内移动短板至 S(i+1,j)S(i + 1, j)S(i+1,j) ，则相当于消去了 S(i,j−1),S(i,j−2),...,S(i,i+1){S(i, j - 1), S(i, j - 2), ... , S(i, i + 1)}S(i,j−1),S(i,j−2),...,S(i,i+1) 状态集合。而所有消去状态的面积一定都小于当前面积（即 <S(i,j)< S(i, j)<S(i,j)），因为这些状态：

    短板高度：相比 S(i,j)S(i, j)S(i,j) 相同或更短（即 ≤h[i]\leq h[i]≤h[i] ）；
    底边宽度：相比 S(i,j)S(i, j)S(i,j) 更短；
    因此，每轮向内移动短板，所有消去的状态都 不会导致面积最大值丢失 ，证毕。


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