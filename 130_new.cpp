#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        vector<vector<char>> table(board.size(), vector<char>(board[0].size(), 0)); //记录走过的'O'
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, table);
            }
        }
    }
    //被围起来了返回true 没被围起来返回false
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<char>> &table) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) { //越界说明此方向没被围起来
            return false;
        }
        if (table[i][j] == 1) { //'O'已经走过了
            return false;
        }
        if (board[i][j] == 'X') { //抵达X说明此方向被围起来了
            return true;
        }
        table[i][j] = 1;  //mark 'O'走过的路线
        if (dfs(board, i, j+1, table) && dfs(board, i, j-1, table)
             && dfs(board, i+1, j, table) && dfs(board, i-1, j, table)) {
            board[i][j] = 'X';
            return true;
        }
        return false;
    }
};
int main() {
    //vector<vector<char>> board {vector<char>{'X','X','X','X'},vector<char>{'X','O','O','X'},vector<char>{'X','X','O','X'},vector<char>{'X','O','X','X'}};
    //vector<vector<char>> board {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    vector<vector<char>> board {{'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}};
    (new Solution)->solve(board);
    return 0;
}
