//这题动态规划直接用了自底向上,因为自顶向下要保存一个profit_table[],和一个min_buy_before[]空间复杂度太大,而且速度会因为哈希表而变慢
//状态转移方程:1.min_buy_table[i] = min{min_buy_table[i - 1], prices[i]}
//2.profit_table[i] = max{profit_table[i - 1], prices[i] - min_buy_table[i]}
//有两个状态转移方程时用自底向上可能会更好一些
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        //unordered_map<int, int> min_buy;
        //unordered_map<int, int> profit_table;
        int min_buy_before;
        int profit_before;
        for (int i = 0; i <= prices.size() - 1; i++) {
            if (i == 0) {
                min_buy_before =  prices[i];
                profit_before = 0;
            } else {
                min_buy_before = std::min(min_buy_before, prices[i]);
                profit_before = std::max(prices[i] - min_buy_before, profit_before);
            }
        }
        return profit_before;
    }
};

