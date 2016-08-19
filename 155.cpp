class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_ele = INT_MAX;
    }
    
    void push(int x) {
        s_int.push(x);
        min_ele = std::min(min_ele, x);
    }
    
    void pop() {//这题最需要注意的地方就是pop(),要用到一个临时的栈,而且时间复杂度会是O(n)
        if (min_ele == s_int.top()) {
            s_int.pop();
            min_ele = INT_MAX;
            stack<int> temp;
            while (!s_int.empty()) {
                min_ele = std::min(min_ele, s_int.top());
                temp.push(s_int.top());
                s_int.pop();
            }
            while (!temp.empty()) {
                s_int.push(temp.top());
                temp.pop();
            }
        } else {
            s_int.pop();
        }
    }
    
    int top() {
        return s_int.top();
    }
    
    int getMin() {
        return min_ele;
    }
private:
    stack<int> s_int;
    int min_ele;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
