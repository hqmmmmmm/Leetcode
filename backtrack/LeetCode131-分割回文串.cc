// 这题在判断切割出来的部分是否为回文子串时，还可以使用动态规划进行优化
// https://www.programmercarl.com/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.html#%E6%80%9D%E8%B7%AF

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int startIndex, string s)
    {
        if(startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); ++i)
        {
            // 切割位置在i和i+1之间
            string tmp = s.substr(startIndex, i - startIndex + 1);
            if(check(tmp))  // 是回文子串
            {
                path.push_back(tmp);
                dfs(i + 1, s);
                path.pop_back();
            }                
            else
                continue;
        }
    }

    bool check(string str)
    {
        for(int i = 0, j = str.size() - 1; i < j; ++i, --j)
            if(str[i] != str[j])
                return false;
        return true;
    }
};