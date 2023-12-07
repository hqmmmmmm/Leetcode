// Leetcode438.找到字符串中所有字母异位词
/*
    定义一个长度为26数组counts保存p中出现的所有字母的次数，
    遍历s，维护一个长度为p.size()的滑动窗口，
    定义另一个长度为26的数组curCounts保存窗口中出现的所有字母的次数，
    每次判断curCounts和counts是否相等，相等则将此时窗口的left下标push到ans中。
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> counts(26);
       
        if(s.size() < p.size()) 
            return ans;

        vector<int> curCounts(26);
        for(const auto &c : p) 
            counts[c - 'a']++;
        
        for(int i = 0; i <= p.size() - 1; ++i)
            curCounts[s[i] - 'a']++;
        if(counts == curCounts)
            ans.push_back(0);
        
        for(int left = 1, right = p.size(); right < s.size(); ++left, ++right)
        {
            curCounts[s[left - 1] - 'a']--;
            curCounts[s[right] - 'a']++;
            if(counts == curCounts)
                ans.push_back(left);
        }
        return ans;
    }
};