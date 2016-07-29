//先找行再找列是错误的，所以做不到O(lgm + lgn)的时间复杂度

//O(mlgn) 1200ms
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i <= matrix.size() - 1; i++) {
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (it != matrix[i].end() && *it == target) {
                return true;
            }
            
        }
        return false;
    }
};*/
//O(m + n)从左下角或者右上角出发，这个比较难想到，最好记住，下次能直接答上来
//右上角(行的最大值，列的最小值)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        for (;i <= matrix.size() - 1 && j >= 0 ; ) {//超过边界就说明没找到target
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target){
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};
