#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    //先将矩阵沿对角线swap，在一行一行翻转vector<int>
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++) {
                swap(matrix[i][j], matrix[i][size - j - 1]);
            }
        }

    }
};
int main() {

    vector<vector<int>> nums = {  
      {5, 1, 9,11},
      {2, 4, 8,10},
      {13, 3, 6, 7},
      {15,14,12,16}
    };
    (new Solution())->rotate(nums);
    return 0;
}
