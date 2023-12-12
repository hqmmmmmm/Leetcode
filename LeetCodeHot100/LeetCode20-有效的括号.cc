class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        
        stack<char> stk;
        unordered_map<char, char> h = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(auto &c : s)
        {
            if(h.count(c))
            {
                if(stk.empty() || stk.top() != h[c])   // 不匹配提前结束
                    return false;
                stk.pop();
            }
            else
                stk.push(c);
        }
        return stk.empty();
    }
};