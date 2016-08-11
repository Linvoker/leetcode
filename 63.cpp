//此题与62题状态转移方程略有不同:1.f(m,n) = f(m,n-1) + f(m-1, n), m != 1 && n != 1; 2.f(m,n) = f(m,n-1) ,m = 1时; 3.f(m,n) = f(m-1, n), n = 1时;
//table里的存有table[0][0]的那一行和那一列全都这不存步数,从table[1][1]开始存
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> init_table(n + 1, -1);
        vector<vector<int>> table(m + 1, init_table);
        return helper(m, n, table, obstacleGrid);
    }
    int helper(int m , int n, vector<vector<int>> &table, vector<vector<int>>& obstacleGrid) {
        //和62题不一样,如果mn只有一个为1,并不能根据右下角是否等于1判断此路通不通.
        
            if (obstacleGrid[obstacleGrid.size() - m][obstacleGrid[0].size() - n] == 1) {//当前位置上是1时,说明此路不通
                return table[m][n] = 0;
            } else if (table[m][n] == -1) {//当前位置上是0,此路可通,并且table里还没保存此格的步数时
                if (m == 1 && n == 1) {//m和n同时等于1时,table[1][1]的值与地图右下角是否等于1有关
                    return table[m][n] = 1;
                } else if (m == 1) {
                    return table[m][n] = helper(m, n - 1, table, obstacleGrid);
                } else if (n == 1) {
                    return table[m][n] = helper(m - 1, n, table, obstacleGrid);
                } else {
                    return table[m][n] = helper(m, n - 1, table, obstacleGrid) + helper(m - 1, n, table, obstacleGrid);
                }
            } else {
                return table[m][n];
            }
        
    }
};
