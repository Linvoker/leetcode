//
//这个backtracking有点像51. N-Queens，但比51题难，不过因为这题可以用动态规划做，所以通过率比较高

//改进版
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool mark = 1;
        
       /* int row_temp = 0;//找到第一个'.'
        int column_temp = 0;
        findNextPosition(row_temp, column_temp, board);//找到第一个'.'的位置
        */
        backTracking(board, 0, 0, mark);
    }
    void backTracking(vector<vector<char>> &trace, int row_index, int column_index, bool &mark) {
        if (row_index == 9) {
            mark = 0;
            return;
        }
            
        for (int i = 1; i <= 9; i++) {
            if (!isValid(row_index, column_index, i, trace)) {
                continue;
            }
            if (trace[row_index][column_index] == '.') {//这个是为了防止数独的第一个格子就是有数字而非'.'的情况
                trace[row_index][column_index] = '0' + i;
            }
            
            int row_temp = row_index;
            int column_temp = column_index;
            findNextPosition(row_temp, column_temp, trace);//找到下一个'.'的位置

            backTracking(trace, row_temp, column_temp, mark);
            if (mark) {//直接返回
            trace[row_index][column_index] = '.';
            }
        }
        return;
    }
    bool isValid(int row_index, int column_index, int val, vector<vector<char>> &trace) {
       // int major_pos = (row_index / 3) * 3 + column_index / 3;//小方格的位置，其实没用到
        for (int i = 0; i <= 8; i++) {
            if (trace[i][column_index] == '0' + val) {
                return false;
            }
        }
        for (int j = 0; j <= 8; j++) {
            if (trace[row_index][j] == '0' + val) {
                return false;
            }
        }
        int min_row = row_index < 3 ? 0 : (row_index < 6 ? 3 : 6);//针对小方格
        int min_column = column_index < 3 ? 0 : (column_index < 6 ? 3 : 6);
        int i = min_row; 
        int j = min_column;
        while (i != min_row + 3) {
            if (trace[i][j] == '0' + val) {
                return false;
            }
            
            if (j == min_column + 2) {
                i++;
                j = min_column;
            } else {
                j++;
            }
        }
        return true;
    }
    void findNextPosition(int &row_temp, int &column_temp, vector<vector<char>> &board) {
        while (row_temp != 9 && board[row_temp][column_temp] != '.') {
            if (column_temp == 8) {
                row_temp++;
            } 
            column_temp = (column_temp + 1) % 9;
        }
    }
    
};
/*
//原始版
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ret_vec;
        bool mark = 1;
        
        int row_temp = 0;//找到第一个'.'
        int column_temp = 0;
        findNextPosition(row_temp, column_temp, board);//找到第一个'.'的位置
        
        backTracking(ret_vec, board, row_temp, column_temp, mark);
        board = ret_vec;
    }
    void backTracking(vector<vector<char>> &ret_vec, vector<vector<char>> &trace, int row_index, int column_index, bool &mark) {
        if (row_index == 9) {
            mark = 0;
            ret_vec = trace;
            return;
        }
            
        for (int i = 1; i <= 9 && mark; i++) {
            if (!isValid(row_index, column_index, i, trace)) {
                continue;
            }
            
            trace[row_index][column_index] = '0' + i;
            
            int row_temp = row_index;
            int column_temp = column_index;
            findNextPosition(row_temp, column_temp, trace);//找到下一个'.'的位置

            backTracking(ret_vec, trace, row_temp, column_temp, mark);
            //if (mark) {
            trace[row_index][column_index] = '.';
            //}
        }
        return;
    }
    bool isValid(int row_index, int column_index, int val, vector<vector<char>> &trace) {
       // int major_pos = (row_index / 3) * 3 + column_index / 3;
        for (int i = 0; i <= 8; i++) {
            if (trace[i][column_index] == '0' + val) {
                return false;
            }
        }
        for (int j = 0; j <= 8; j++) {
            if (trace[row_index][j] == '0' + val) {
                return false;
            }
        }
        int min_row = row_index < 3 ? 0 : (row_index < 6 ? 3 : 6);
        int min_column = column_index < 3 ? 0 : (column_index < 6 ? 3 : 6);
        int i = min_row; 
        int j = min_column;
        while (i != min_row + 3) {
            if (trace[i][j] == '0' + val) {
                return false;
            }
            
            if (j == min_column + 2) {
                i++;
                j = min_column;
            } else {
                j++;
            }
        }
        return true;
    }
        void findNextPosition(int &row_temp, int &column_temp, vector<vector<char>> &board) {
            while (row_temp != 9 && board[row_temp][column_temp] != '.') {
                if (column_temp == 8) {
                    row_temp++;
                } 
                column_temp = (column_temp + 1) % 9;
            }
        }

};
