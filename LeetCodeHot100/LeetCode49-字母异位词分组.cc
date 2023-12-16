// // 排序
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> h;
//         vector<vector<string>> res;

//         for(auto &str : strs)
//         {
//             string key = str;
//             sort(key.begin(), key.end());
//             h[key].push_back(str);
//         }

//         for(auto &[k, v] : h)
//             res.push_back(v);
            
//         return res;
//     }
// };

// 计数
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 当unordered_map的键是自定义类型时，要自己定义哈希函数，这个做法懂了就行。
        unordered_map<vector<int>, vector<string>> h;  
        vector<vector<string>> res;

        for(auto &str : strs)
        {
            vector<int> curCount(26, 0);
            for(auto &c : str) 
                curCount[c - 'a']++;
            h[curCount].push_back(str);
        }

        for(auto &[k, v] : h)
            res.push_back(v);
            
        return res;
    }
};