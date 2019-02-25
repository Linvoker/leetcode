#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    //记录上下左右边界，粗暴地螺旋着读数据，做着题算是消遣时间吧没啥实际意义
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int upMost = -1, rightMost = -1, downMost = -1, leftMost = -1;
        int i = 0, j = 0;
        vector<int> res;
        while (1) {
            bool has_next1 = false;
            while (j < (int)matrix[i].size() && (rightMost == -1 || j < rightMost)) {
                has_next1 = true;
                upMost = i;
                res.push_back(matrix[i][j++]);
            }
            if (has_next1) {
                j--;
            } else {
                break;
            }
            i++;

            bool has_next2 = false;
            while (i < (int)matrix.size() && (downMost == -1 || i < downMost)) {
                has_next2 = true;
                rightMost = j;
                res.push_back(matrix[i++][j]);
            }
            if (has_next2) {
                i--;
            } else {
                break;
            }
            j--;

            bool has_next3 = false;
            while (j >= 0 && (leftMost == -1 || j > leftMost)) {
                has_next3 = true;
                downMost = i;
                res.push_back(matrix[i][j--]);
            }
            if (has_next3) {
                j++;
            } else {
                break;
            }
            i--;

            bool has_next4 = false;
            while (i >= 0 && (upMost == -1 || i > upMost)) {
                has_next4 = true;
                leftMost = j;
                res.push_back(matrix[i--][j]);
            }
            if (has_next4) {
                i++;
            } else {
                break;
            }
            j++;
            
        }
        return res;
    }
};
int main () {
    vector<vector<int>> matrix{
          {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9,10,11,12}
        /* { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 } */
    };
    (new Solution)->spiralOrder(matrix);
}
