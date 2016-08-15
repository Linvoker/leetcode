//有点像72. Edit Distance
//The problem itself is very difficult to understand. It can be stated like this:
//Give a sequence S and T, how many distinct sub sequences from S equals to T?
//题目出的有问题,没有描述清楚:https://discuss.leetcode.com/topic/402/task-clarification/11
//状态转移方程(无意中试出来的): 1.f(n, m) = f(n - 1, m) + f(n - 1, m - 1), s[n - 1] == t[m - 1]
//2.f(n ,m) = f(n - 1, m), s[n - 1] != t[m - 1]
//If t[m - 1] == s[n - 1], the number of distinct subsequences include two parts: those with t[m - 1] and those without;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> table(s.size() + 1, vector<int>(t.size() + 1, -1));//table[0]不存数
        return helper(s, t, s.size(), t.size(), table);
    }
    int helper(string &s, string &t, int n , int m, vector<vector<int>> &table) {//n和m是长度范围
        if (table[n][m] != -1) {
            return table[n][m];
        }
        if (n == 0 && m != 0) {
            return 0;
        }
        if (m == 0) {
            return 1;
        }
        /*if (s[n - 1] == t[m - 1]) {
            return table[n][m] = helper(s, t, n - 1, m, table) + helper(s, t, n - 1, m - 1, table);
        } else {
            return table[n][m] = helper(s, t, n - 1, m, table);
        }*/
        return table[n][m] = helper(s, t, n - 1, m, table) + (s[n - 1] == t[m - 1] ? helper(s, t, n - 1, m - 1, table) : 0);
    }
};
