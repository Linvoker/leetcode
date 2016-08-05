//不考虑tag的backtrace，第一直觉会用栈来做，但其实栈只能用于判断一个序列的括弧是否放置正确
//而用栈来做必须列出所有排列组合的情况，这个有点复杂，我没想到好办法。

//解空间为6层的二叉树，记录左括弧右括弧的数量，剪枝函数就用这个了。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> parentheses = {'(', ')'};
        vector<string> ret_vec;
        string ret_str;
        backtracing(ret_vec, ret_str, 0, 0, parentheses, n);
        return ret_vec;
    }
    void backtracing(vector<string> &ret_vec, string &ret_str, 
             int num_left_parentheses, int num_right_parentheses, const vector<char> &parentheses, const int n) {
        if (ret_str.size() == n * 2) {
            if (num_left_parentheses == n) {
                ret_vec.push_back(ret_str);//输出结果（递归因正常结束而返回）
            }
            return;
        }
        for (int i = 0; i <= 1; i++) {//枚举所有可能性（由解空间的树的分支数目决定）
        //其实如果分支数永远都是固定的并小于等于三，那么不用for不用了vector<char> parentheses也不用了，直接顺序写就行
            if (num_left_parentheses < num_right_parentheses || num_left_parentheses == n + 1) {//剪枝函数
                return;
            }
            ret_str.push_back(parentheses[i]);
            if (i == 0) {
                num_left_parentheses++;
            } else {
                num_right_parentheses++;
            }
            backtracing(ret_vec, ret_str, num_left_parentheses, num_right_parentheses, parentheses, n);
            ret_str.pop_back();
            if (i == 0) {
                num_left_parentheses--;
            } else {
                num_right_parentheses--;
            }
        }
    }
};
