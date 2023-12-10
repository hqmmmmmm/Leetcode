class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0, ans = 0;

        while(j < nums.size())
        {
            if(nums[j] == 0)
            {
                if(cnt < k) 
                    cnt++;
                else
                {
                    while(nums[i]) ++i;
                    ++i;
                }
            }
            ++j;
            ans = max(ans, j - i);
        }
        return ans;
    }
};