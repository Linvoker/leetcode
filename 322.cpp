//动态规划自顶向下,table[amount] = 1 + min{table[amount - coins[i]]},0 <= i < coins.size() && amount - coins[i] >= 0
//O(n * amount)的时间复杂度,O(amount)的空间复杂度
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, -2);//-2只是一个标志
        int temp = helper(coins, amount, table);
        return temp == INT_MAX ? -1 : temp;//返回了INT_MAX说明所有路不通
    }
    int helper(vector<int> &coins, int amount, vector<int> &table) {
        
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;//这条路无法凑到amount
        }
        if (table[amount] != -2) {//表里已有
            return table[amount];
        }
        
        int ret_val = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            ret_val = std::min(ret_val, helper(coins, amount - coins[i], table));//因为不通(无法凑出amount)的路返回INT_MAX,所以不会列入考虑的
        }
        /*if (ret_val == INT_MAX) {//此路下面所有路都凑不到amount
            return table[amount] = INT_MAX;
        } else {//之所以不在循环里+1就是因为上面的if里INT_MAX这个标志不能+1
            return table[amount] = ret_val + 1;
        }*/
        return table[amount] = (ret_val == INT_MAX) ? INT_MAX : ret_val + 1;
    }
};
