class Solution {
public:
    vector<string> res;
    string path;
    int n;
    unordered_map<char, string> mp;

    vector<string> letterCombinations(string digits) {
        n = digits.size();
        mp = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        dfs(0, digits);
        return res;
    }

    void dfs(int u, string digits)
    {
        if(u == n)
        {
            if(path.size())
                res.push_back(path);
            return;
        }
        for(int i = 0; i < mp[digits[u]].size(); ++i)
        {
            path.push_back(mp[digits[u]][i]);
            dfs(u + 1, digits);
            path.pop_back();
        }
    }




};