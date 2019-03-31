#include<vector>
#include<iostream>
#include<stack>
//#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    //dfs
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (dfs(grid, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    //第一次登录这篇岛屿返回true
    bool dfs(vector<vector<char>>& grid, int i,int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) { //边界
            return false;
        }
        if (grid[i][j] < '1') {
            return false;//0 已经走过这个岛屿了或者是water
        }
        grid[i][j] = '0'; //走过了就变水，用以区分第一次及终止遍历
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        return true;
    }
};
int main() {
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout << (new Solution)->numIslands(grid) << endl;
}
