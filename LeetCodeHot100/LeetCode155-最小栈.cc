// 双栈实现
class MinStack {
    stack<int> stk;      // 存储所有元素的栈
    stack<int> min_stk;  // 存储最小元素的栈
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(!min_stk.empty() && min_stk.top() < val)
            min_stk.push(min_stk.top());
        else
            min_stk.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};



// 单栈实现
class MinStack {
    stack<long long> stk;  // 存放栈顶元素与(其它元素)最小值的差值
    long long curmin;      // curmin存储的是栈中所有元素的最小值
public:
    MinStack() {
        curmin = INT64_MAX;
    }
    
    void push(int val) {
        if(stk.empty())
        {
            stk.push(0);
            curmin = val;
        }
        else
        {
            long long sub = val - curmin;
            stk.push(sub);  // 所以说存储的是栈顶元素和其它所有元素的最小值的差值，curmin存储的是栈中所有元素的最小值
            if(sub < 0)  // 当前最小值需要更新
                curmin += sub;
        }
    }
    
    void pop() {
        if(stk.top() <= 0)
            curmin -= stk.top();
        stk.pop();
    }
    
    int top() {
        if(stk.top() <= 0)
            return curmin;
        return curmin + stk.top();
    }
    
    int getMin() {
        return curmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */