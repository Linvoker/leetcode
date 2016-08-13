//f(n) = 1 + min{f(n - 1^2), f(n - 2^2), f(n - 3^2)...直到n<x^2}
//自顶向下
//leetcode上的耗时是指所有case一共花费的时间,每次调用numSquares(n),都要新建一个table,这其实可以被优化的,用static dynamic programming可以解决
//只需将table变成static存储即可,但由于自顶向下的缘故,这像是作弊,不过自底向上就完全没问题
//static dynamic programming的前提条件是函数的参数是数目而非vector之类的东西
/*class Solution {
public:
    
    int numSquares(int n) {
        static vector<int> table(9996, -1);//这是测试的最大数据n = 9995
        table[0] = 0;
        return helper(table, n);
    }
    int helper(vector<int> &table, int n) {
        if (table[n] != -1) {
            return table[n];
        }
        int min = INT_MAX;
        for (int i = 1; n >= i * i; i++) {
            min = std::min(min, helper(table, n - i * i));
        }
        return table[n] = min + 1;
    }
};*/
//自底向上,将0-n的每一个numSquares()都算了一遍并存储了起来,但自顶向上只存储了计算numsSquares(n)必要的那些值,但自顶向下的时间更长
//别人想到的
class Solution {
public:
    
    int numSquares(int n) {
    static vector<int> dp {0};
    while (dp.size() <= n) {
        int m = dp.size(), squares = INT_MAX;
        for (int i=1; i*i<=m; ++i)
            squares = min(squares, dp[m-i*i] + 1);
        dp.push_back(squares);
    }
    return dp[n];

    }
   
};
