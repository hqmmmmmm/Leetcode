// // 排序
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         return nums[n / 2];
//     }
// };

// 哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto &num : nums)
            if(++mp[num] > n / 2)
                return num;
        return 0;
    }
};