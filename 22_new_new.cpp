#include<iostream>
#include<vector>
#include<stack>
//#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int leftNum = 0; //当前还未被右括号抵消的左括号个数
        int maxLeftNum = 0; //当前左括号的总数，用于递归剪枝函数
        vector<string> res;
        string trace;

        backTrace(trace, res, leftNum, maxLeftNum, 2 * n, n);
        return res;
    }
    void backTrace(string trace, vector<string> &res, int leftNum, int maxLeftNum, int n, int maxn) {
        if (n == 0) {
            if (leftNum == 0) {
                res.push_back(trace);
            } 
            return;
        }
        
        //左括号(
        if (maxLeftNum++ < maxn) {
            leftNum++;
            trace.push_back('(');
            backTrace(trace, res, leftNum, maxLeftNum, n - 1, maxn);
            leftNum--;
            trace.pop_back();
        }
        maxLeftNum--;
        
        //右括号)
        if (leftNum == 0) {
            return; 
        }
        leftNum--;
        trace.push_back(')');
        backTrace(trace, res, leftNum, maxLeftNum, n - 1, maxn);
    }
};
int main()
{
    auto x = (new Solution)->generateParenthesis(5);
    return 0;
}
