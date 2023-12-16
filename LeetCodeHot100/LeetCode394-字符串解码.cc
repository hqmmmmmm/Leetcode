// 方法一：栈
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ']') stk.push(s[i]);
            else
            {   
                // 得到当前[]内的字符串
                string tmp = "";
                while(stk.top() != '[')
                {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                stk.pop();
                
                // 获取当前[]前面的数字，不一定是个位数
                string cnt_str = "";
                while(!stk.empty() && isdigit(stk.top()))
                {
                    cnt_str = stk.top() + cnt_str;
                    stk.pop();
                }    
                int cnt = stoi(cnt_str);            
                
                // 将cnt个[]内的字符串push到栈中
                while(cnt--)
                    for(auto &c : tmp) stk.push(c);
            }
        }

        // 将栈中的字符串返回
        string ans = "";
        while(!stk.empty()) 
        {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};

  
// 方法二：递归
