// Leetcode31.下一个排列
/*
 感觉并不算双指针的题目。
 应该从右往左考虑，找到第一个非降序的元素，将它变大（进行最小幅度的变大），得到的就是下一个排列
 如果没有非降序的元素，说明这是最大的排列(直接reverse即可）；
 如果找到了第一个非降序的元素z，直接将它与后面大于它但最小的元素交换，然后再reverse后面的部分（确保是下一个排列）。
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while(k > 0 && nums[k] <= nums[k - 1]) --k;

        if(k == 0) 
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {
            int t = nums.size() - 1;
            while(nums[t] <= nums[k - 1]) --t;

            swap(nums[k - 1], nums[t]);

            reverse(nums.begin() + k, nums.end());
        }
    }
};


