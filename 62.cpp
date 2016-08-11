//because std don't know how to hash a pair<int, int>,所以unordered_map<pair<int, int>, int>必须要自己写hash函数
//状态转移方程:f(m,n) = f(m,n-1) + f(m-1, n)
//自顶向下
/*class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int, int>, int> table;
        return helper(m, n, table);
    }
    int helper(int m , int n, map<pair<int, int>, int> &table) {
        if (m == 1 || n == 1) {
            table[{1, 1}] = 1;
            return 1;
        } else {
            if (table.find({m, n}) == table.end()) {
                return table[make_pair(m, n)] = helper(m, n - 1, table) + helper(m - 1, n, table);
                //return table[{m, n}] = helper(m, n - 1, table) + helper(m - 1, n, table);
            } else {
                return table[make_pair(m, n)];
                //return table[{m, n}];
            }
        }
    }
};*/
//用vector代替map存储table
//table里的存有table[0][0]的那一行和那一列全都这不存步数,从table[1][1]开始存
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> init_table(n + 1, -1);
        vector<vector<int>> table(m + 1, init_table);
        return helper(m, n, table);
    }
    int helper(int m , int n, vector<vector<int>> &table) {
        if (m == 1 || n == 1) {//只要位置变成最后一行或者最后一列,那么就将返回1种办法,并且table[1][1]赋值为1(虽然这样会导致多次赋值给该位置).
            table[1][1] = 1;
            return 1;
        } else {
            if (table[m][n] == -1) {
                return table[m][n] = helper(m, n - 1, table) + helper(m - 1, n, table);
                //return table[{m, n}] = helper(m, n - 1, table) + helper(m - 1, n, table);
            } else {
                return table[m][n];
                //return table[{m, n}];
            }
        }
    }
};
