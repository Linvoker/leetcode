//这也是一类题型
//以board为candidates
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); i++) {//先找到第一个与word[0]匹配的坐标才能调用backTracking函数
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char reserve = board[i][j];//路线不同返回时要把'.'变回原样
                    board[i][j] = '.';//用'.'标示已走过的路线
                    bool mark = 0;
                    backTracking(board, word, 1, i, j, mark);
                    if (mark) {
                        return true;
                    }
                    board[i][j] = reserve;//原路返回不破坏结构
                }
            }
            
        }
        return false;
    }
    //row和column是candidates里匹配了当前word里的字符并已经放入'.'的坐标，str_index是word的下一个要匹配的字符
    void backTracking(vector<vector<char>>& candidates, const string &word, int str_index, int row, int column, bool &mark) {
        if (str_index == word.size()) {
            mark = 1;
            return;
        }
        int count = 4;
        while (count--) {
            switch (count) {//周围4个position轮流匹配一遍
                case 3 : column--; break;
                case 2 : column++; row--; break;
                case 1 : row += 2; break;
                case 0 : row--; column++;
            }
            if (row < 0 || row >= candidates.size() || column < 0 || column >= candidates[0].size() 
                     || word[str_index] != candidates[row][column]) {
                continue;
            }
            char reserve = candidates[row][column];
            candidates[row][column] = '.';
            
            backTracking(candidates, word, str_index + 1, row, column, mark);
            
            if (!mark) {//如果没有这一句会出现time limit excceed。我们确认存在后不用去管board的还原了
                candidates[row][column] = reserve;//原路返回不破坏结构
            } else {
                break;
            }
        }
        return;
    }

};

//和上面版本的差别只在于mark用返回值bool代替了
/*class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char reserve = board[i][j];//路线不同返回时要把'.'变回原样
                    board[i][j] = '.';//用'.'标示已走过的路线
                    
                    if (backTracking(board, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = reserve;
                }
            }
            
        }
        return false;
    }
    bool backTracking(vector<vector<char>>& candidates, const string &word, int str_index, int row, int column) {
        if (str_index == word.size()) {
            return true;
        }
        int count = 4;
        while (count--) {
            switch (count) {//周围4个position轮流匹配一遍
                case 3 : column--; break;
                case 2 : column++; row--; break;
                case 1 : row += 2; break;
                case 0 : row--; column++;
            }
            if (row < 0 || row >= candidates.size() || column < 0 || column >= candidates[0].size() 
                     || word[str_index] != candidates[row][column]) {
                continue;
            }
            char reserve = candidates[row][column];
            candidates[row][column] = '.';
            
            if (!backTracking(candidates, word, str_index + 1, row, column)) {
                candidates[row][column] = reserve;
            } else {
                return true;
            }
        }
        return false;
    }

};

