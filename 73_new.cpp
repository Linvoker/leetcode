class Solution {
public:
    //用第一行第一列记录各行各列的清零需求 空间复杂度O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        
        bool row_mark = false, col_mark = false;// 提前记录第一行第一列是否需要清零
        for (int i = 0; i < row_size; i++) {
            if (matrix[i][0] == 0) {
                row_mark = true;
            }
        }
        for (int j = 0; j < column_size; j++) {
            if (matrix[0][j] == 0) {
                col_mark = true;
            }
        }
        
        //用第一行第一列记录清零请求
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //清零非第一行
        for (int i = 1; i < row_size; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < column_size; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        //清零非第一列
        for (int j = 1; j < column_size; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < row_size; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //清零第一行第一列
        if (row_mark) {
            for (int i = 0; i < row_size; i++) {
                matrix[i][0] = 0;
            }
        } 
        if (col_mark) {
            for (int j = 0; j < column_size; j++) {
                matrix[0][j] = 0;
            }
        }
    }
    //空间复杂度O(n+m), 先扫一遍matrix，将需要清零的行和列记录到row和column里
    /*void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        vector<int> row(row_size, 0);
        vector<int> column(column_size, 0);
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (row[i] == 1 || column[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }*/
};
