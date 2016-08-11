//自顶向下
//状态转换方程:f(x,y) = triangle[x][y] + min{f(x+1,y) + f(x+1,y+1)}
/*class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> table;
        for (int i = 0; i < triangle.size(); i++) {//初始化table空间复杂度为O(n+n-1+n-2+...1)n为深度
            table.push_back(vector<int>(triangle[i].size(), INT_MIN));
        }
        return helper(triangle, table, 0, 0);
    }
    int helper(vector<vector<int>> &triangle, vector<vector<int>> &table, int x_index, int y_index) {
        if (x_index == triangle.size() - 1) {
            return table[x_index][y_index] = triangle[x_index][y_index];
        }
        if (table[x_index][y_index] != INT_MIN) {
            return table[x_index][y_index];
        } else {
            return table[x_index][y_index] = triangle[x_index][y_index] + 
                     std::min(helper(triangle, table, x_index + 1, y_index), helper(triangle, table, x_index + 1, y_index + 1));
        }
    }
};*/
//自底向上,空间复杂度为O(n),n为深度
//从底端考虑每层第j个元素到底层的最短距离为下一层第j个元素与第j+1个元素离底层最短距离更小的那个加上该层第j个元素的值,以此类推,每层会少一个table[尾部]
//画图更好理解
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> table(triangle.back());//最底层元素的数量
        for (int i = triangle.size() - 2; i >= 0; i--) {//从倒数第二层开始
            for (int j = 0; j < triangle[i].size(); j++) {
                table[j] = triangle[i][j] + std::min(table[j], table[j+1]);
            }
        }
        return table[0];
    }
};
