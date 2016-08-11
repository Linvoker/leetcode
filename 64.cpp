//自顶向下,状态转移方程:f(x,y) = grid[x][y] + min{f(x+1,y), f(x,y+1)}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> table(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid, 0, 0, table);
    }
    int helper(vector<vector<int>> &grid, int x_index, int y_index, vector<vector<int>> &table) {
            if (table[x_index][y_index] != -1) {//r如果table里存有该结点路径的最小值,则直接返回
                return table[x_index][y_index];
            } else {
                if (x_index == grid.size() - 1 && y_index == grid[0].size() - 1) {//右下角
                    return table[x_index][y_index] = grid[x_index][y_index];
                } else if (x_index == grid.size() - 1) {//最右边一列
                    return table[x_index][y_index] = grid[x_index][y_index] + helper(grid, x_index, y_index + 1, table);
                } else if (y_index == grid[0].size() - 1) {//最下面一行
                    return table[x_index][y_index] = grid[x_index][y_index] + helper(grid, x_index + 1, y_index, table);
                } else {//中间位置
                    return table[x_index][y_index] = grid[x_index][y_index] + 
                             std::min(helper(grid, x_index + 1, y_index, table), helper(grid, x_index, y_index + 1, table));
                }
            }
    }
    
};
