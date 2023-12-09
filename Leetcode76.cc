class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> hasht;
        unordered_map<char, int> hashs;
        for(auto &c : t) hasht[c]++;

        string ans = s + t;
        int i = 0, j = 0;
        while(j < s.size())
        {
            if(hasht.count(s[j])) hashs[s[j++]]++;
            else ++j;
            
            // 去除前面不在t中的字符
            while(!hasht.count(s[i]) || hashs[s[i]] > hasht[s[i]])
            {
                if(!hasht.count(s[i])) ++i;
                else hashs[s[i++]]--;

                if(i >= j) break;
            }

            if(j <= i ) continue;

            bool flag = equal(hashs, hasht);
            if(flag && j - i < ans.size())
                ans = s.substr(i, j - i);
        }

        return ans == s + t ? "" : ans;
    }

    bool equal(unordered_map<char, int> &h1, unordered_map<char, int> &h2) 
    {
        for(auto &[k, v] : h2)
        {
            if(h1.count(k) && h1[k] >= h2[k])
                continue;
            else return false;
        }
        return true;
    }
};