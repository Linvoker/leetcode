
/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        deque<deque<bool>> table(grid.size(), deque<bool>(grid[0].size(), false));//用一个表来记录深度优先搜索走过的路线
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {//遍历每一格,如果格子没有被遍历过的并且格子里是'1',则进行深度优先搜索看看有多少相邻的'1'
            for (int j = 0; j < grid[0].size(); j++) {
                if (table[i][j] == false && grid[i][j] == '1') {
                    dfs(grid, table, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(const vector<vector<char>> &grid, deque<deque<bool>> &table, int i, int j) {
        
        table[i][j] = true;//一定要先标志为true,最后再标会陷入死循环
        if (i < grid.size() - 1 && grid[i + 1][j] == '1' && table[i + 1][j] == false) {//下
            dfs(grid, table, i + 1, j);
        }
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1' && table[i][j + 1] == false) {//右
            dfs(grid, table, i, j + 1);
        }
        if (i > 0 && grid[i - 1][j] == '1' && table[i - 1][j] == false) {//上
            dfs(grid, table, i - 1, j);
        }
        if (j > 0 && grid[i][j - 1] == '1' && table[i][j - 1] == false) {//左
            dfs(grid, table, i, j - 1);
        }
        
        return;
    }
};*/
//deque是不必要的,将已经遍历过的格子标为water('0')即可
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //不用deque就不用判断是否为空了
        /*if (grid.empty()) {
            return 0;
        }*/
        //deque<deque<bool>> table(grid.size(), deque<bool>(grid[0].size(), false));//用一个表来记录深度优先搜索走过的路线
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {//遍历每一格,如果格子没有被遍历过的并且格子里是'1',则进行深度优先搜索看看有多少相邻的'1'
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        
        grid[i][j] = 0;//一定要先标志为true,最后再标会陷入死循环
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') {//下
            dfs(grid, i + 1, j);
        }
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {//右
            dfs(grid, i, j + 1);
        }
        if (i > 0 && grid[i - 1][j] == '1') {//上
            dfs(grid, i - 1, j);
        }
        if (j > 0 && grid[i][j - 1] == '1') {//左
            dfs(grid, i, j - 1);
        }
        
        return;
    }
};
