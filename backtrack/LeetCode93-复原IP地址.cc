// 切割问题，递归枚举切割的位置（即句点.放置的位置）
class Solution {
public:
    vector<string> res;
    vector<string> path;

    vector<string> restoreIpAddresses(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int startIndex, string s)  // startIndex为可以开始切割的位置
    {
        if(startIndex == s.size())
        {
            if(path.size() == 4)
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }
        if(path.size() == 4 || startIndex > s.size())
            return;

        for(int i = startIndex; i < startIndex + 3; ++i)    
        {
            string tmp = s.substr(startIndex, i - startIndex + 1);
            // 数字必须小于255且不能含有前导0
            if(tmp.size() == 3 && tmp > "255" || tmp.size() > 1 && tmp[0] == '0')
                continue;

            path.push_back(tmp);
            dfs(i + 1, s);
            path.pop_back();
        }
    }
};