//51. N-Queens的最后一个思路
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        string temp(n, '.');
        vector<string> trace(n, temp);//将trace初始化为n*n的'.'矩阵，到达终止条件直接可以push_back()
        
        backTracking(trace, 0, n, count);
        return count;
    }
    //传递行的索引row_index和n是为了调用isValid()要用
    void backTracking(vector<string> &trace, int row_index, const int n, int &count) {
        if (row_index == n) {
            count++;
            return;
        }
        for (int i = 0; i <= n - 1; i++) {
            
            if (!isValid(trace, i, row_index, n)) {//剪枝函数
                continue;
            }
            
            trace[row_index][i] = 'Q';
            
            backTracking(trace, row_index + 1, n, count);
            
            trace[row_index][i] = '.';
        }
        return;
    }
    bool isValid(vector<string> &trace, int i, int row_index, int n) {
            for (int j = i, k = row_index; k > 0; ) {//直线O(n)的最坏时间复杂度
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            for (int j = i, k = row_index; j > 0 && k > 0; ) {//对角线之一O(n)的最坏时间复杂度
                j--;
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            for (int j = i, k = row_index; j < n - 1 && k > 0; ) {//对角线之一O(n)的最坏时间复杂度
                j++;
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            return true;
    }
};
