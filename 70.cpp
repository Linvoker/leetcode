//backTracking出现time Limit excceed,因为递归调用的时候计算了大量重复的计算
/*class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        backTracking(n, count);
        return count;
    }
    void backTracking(int n, int &count) {
        if (n == 0) {
            count++;
            return;
        }
        if (n < 0) {
            return;
        }
        for (int i = 0; i < 2; i++) {
            //没有剪枝函数
            if (i == 0) {
                backTracking(n - 1, count);
            } else {
                backTracking(n - 2, count);
            }
        }
    }
};*/
//用动态规划来代替backTracking,自顶向下,用table来存储剩余n步时的办法数量
//状态转移方程:table[n] = table[n - 1] + table[n - 2],是一个斐波那契数列.
/*class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> table;
        return backTracking(n, table);
    }
    int backTracking(int n, unordered_map<int, int> &table) {
        if (n == 0 || n == 1) {
            table[n] = 1;
            return 1;
        }
        if (table.find(n) != table.end()) {
            return table[n];
        } else {
            return table[n] = backTracking(n - 1, table) + backTracking(n - 2, table);
        }    
    }
};*/
//动态规划自底向上
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int first = 1;
        int second = 1;
        int i = 2;
        while (i <= n) {
            int temp = first;
            first = second;
            second = temp + second;
            //table[i] = table[i - 1] + table[i - 2];
            i++;
        }
        return second;
    }
    
};
