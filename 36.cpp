//用三个二维数组保存行／列／子的记录，对应位置为１则冲突，为０则未冲突
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0}, rank[9][9] = {0}, sub[9][9] = {0};
        
        int sub_index;
        int index;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                
                
                if (board[i][j] != '.') {
                    sub_index = i / 3 * 3 + j / 3;//子数组的索引
                    index = board[i][j] - '0' - 1;//'8' - '0' - 1
                
                    if (row[i][index] != 1 && rank[j][index] != 1 && sub[sub_index][index] != 1) {
                        row[i][index] = 1;
                        rank[j][index] = 1;
                        sub[sub_index][index] = 1;
                        
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
