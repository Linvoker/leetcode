#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;

//列出递推公式。时间复杂度O(n)，可以优化成双指针的形式，详见11.cpp
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len =  height.size();
        int maxS = 0;
        maxS = max(dpHelper(height, 0, len - 1), maxS); 
        // for (int i = 0; i < len; i++) {
            // for (int j = 0; j < len; j++) {
                // cout << dptable[i][j] << " ";
            // }
            // cout << endl;
        // }
        return maxS;
    }
    //计算指定范围的最大面积
    int dpHelper(vector<int> &height, int i, int j) {
        if (i + 1 == j) {
            return min(height[i], height[j]);
        }

        if (height[i] > height[j]) {
            return max(dpHelper(height, i, j - 1), (j - i) * min(height[i], height[j])); 
        } else {
            return max(dpHelper(height, i + 1, j), (j - i) * min(height[i], height[j])); 
        }
    }
};
int main () {
    vector<int> z = {
        1,8,6,2,5,4,8,3,7
    };
    vector<int> x = {
        1,1
    };
    Solution y;
    cout << y.maxArea(z) << endl;
    cout << y.maxArea(x) << endl;
}
