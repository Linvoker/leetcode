#include<algorithm>
#include<vector>
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[i].size(); j++) {
                //if (word[0] == board[i][j]) {
                if (backTracking(board, i, j, 0, word)) {
                    return true;
                }
                //}
            }
        }
        return false;
    }
    bool backTracking(vector<vector<char>>& board, int i, int j, int pos, const string &word) {
        if (pos == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == 0 || board[i][j] != word[pos]) { //越界或已经走过
            return false;
        }
        char tmp =  board[i][j];
        board[i][j] = 0;
        if (backTracking(board, i-1, j, pos + 1, word) || backTracking(board, i+1, j, pos + 1, word) || backTracking(board, i, j - 1, pos + 1, word) || backTracking(board, i, j + 1, pos + 1, word)) {
            return true;
        }
        board[i][j] = tmp; //返回false的时候需要还原board
        return false;

    }
    /* bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> mark(board.size() + 1, vector<int>(board[0].size() + 1, 0));
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[i].size(); j++) {
                //if (word[0] == board[i][j]) {
                if (backTracking(board, mark, i, j, 0, word)) {
                    return true;
                }
                //}
            }
        }
        return false;
    }
    bool backTracking(vector<vector<char>>& board, vector<vector<int>>& mark, int i, int j, int pos, const string &word) {
        if (pos == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || mark[i][j] == 1 || board[i][j] != word[pos]) { //越界或已经走过
            return false;
        }
        mark[i][j] = 1;
        return backTracking(board, mark, i-1, j, pos + 1, word) || backTracking(board, mark, i+1, j, pos + 1, word) || backTracking(board, mark, i, j - 1, pos + 1, word) || backTracking(board, mark, i, j + 1, pos + 1, word);
        mark[i][j] = 0;

    } */
};
int main () {
    vector<vector<char>> board = {
        // {'a','b','c','e'},
        // {'s','f','c','s'},
        // {'a','d','e','e'},
        {'c','a','a'},
        {'a','a','a'},
        {'a','a','b'},
    };
    cout << (new Solution())->exist(board, "aab") << endl;
}
