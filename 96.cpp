// we could enumerate each number i in the sequence, and use the number as the root, naturally, the subsequence 1…(i-1) on its left side would lay on
//the left branch of the root, and similarly the right subsequence (i+1)…n lay on the right branch of the root.
//自顶向下,状态转移方程:f(i) = f(1 - 1)*f(i - 1) + f(2 - 1)*f(i - 2) + f(3 - 1)*f(i - 3)...+ f(i - 1)*f(i - i);
//依次以每一个元素为root,计算可能性
class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n + 1, -1);
        return helper(n, table);
    }
    int helper(int n, vector<int> &table) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (table[n] != -1) {
            return table[n];
        } else {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                count += helper(i - 1, table) * helper(n - i, table);
            }
            table[n] = count;
            return count;
            
        }
    }
};
