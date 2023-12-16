// // 暴力（哈希表）
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         unordered_map<int, int> h;
//         vector<int> res(n, 0);

//         for(int i = temperatures.size() - 1; i >= 0; --i)
//         {
//             // 比temperatures[i]大并且距离i最小的元素
//             int minIndex = n;
//             for(int j = temperatures[i] + 1; j <= 100; ++j)
//             {
//                 if(h.count(j))
//                     minIndex = min(minIndex, h[j]);
//             }
            
//             // 存在比temperatures[i]大的元素
//             if(minIndex != n)
//                 res[i] = minIndex - i;
//             h[temperatures[i]] = i;
//         }
//         return res;
//     }
// };


// 单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> res(n, 0);

        for(int i = n - 1; i >= 0; --i)
        {
            // pop出栈顶比当前温度小的温度，因为有temperatures[i]在，这些后面的元素不可能再被用到了
            while(stk.size() && stk.top().first <= temperatures[i])
                stk.pop();

            // 如果此时栈中还有元素，就是大于temperatures[i]且离i最近的元素
            if(stk.size()) res[i] = stk.top().second - i;

            stk.push({temperatures[i], i});
        }
        
        return res;
    }
};



/*

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]


*/