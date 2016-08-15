//状态转移方程:table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]).//table保存的是所有以[i,j]为左上角的最大正方形的边长.
//注意matrix里的'0'和'1'是char不是整数.
//自顶向下
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int res = 0;
        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++) {//遍历所有值找到最大的边长
            for (int j = 0; j < matrix[0].size(); j++) {
                res = std::max(res, sideLength(matrix, i, j, table));
            }
        }
        return res * res;
    }
    int sideLength(vector<vector<char>>& matrix, int i , int j, vector<vector<int>> & table) {
        if (i == matrix.size() || j == matrix[0].size()) {//越界处理
            return 0;
        }
        if (table[i][j] != -1) {
            return table[i][j];
        }
        
        if (matrix[i][j] == '0') {
            return table[i][j] = 0;
        } else {
            int ret_val = 0;
            ret_val = std::min(sideLength(matrix, i + 1, j, table), sideLength(matrix, i, j + 1, table));
            ret_val = std::min(ret_val, sideLength(matrix, i + 1, j + 1, table));
        
            return table[i][j] = ret_val + 1;
        }
    }
};

