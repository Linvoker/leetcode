class Solution {
public:
    int climbStairs(int n) {
        vector<int> table(n + 1, -1);
        return helper(n, table);
    }
    int helper(int n, vector<int> &table) {
        if (n <= 1) {
            return 1;
        }
        if (table[n] != -1) {
            return table[n];
        }
        return table[n] = helper(n - 1, table) + helper(n - 2, table);
    }
};
