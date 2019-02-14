///一个一个遍历过去用O(n^2)原始而没必要。
//一左一右开始哪端的边更小就移动哪段，并记录最大的面积

#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left_point = 0;
        int right_point = height.size() - 1;
        while (left_point != right_point) {
            if (height[left_point] < height[right_point]) {
                max_area = std::max(max_area, height[left_point] * (right_point - left_point));
                left_point++;
            } else {
                max_area = std::max(max_area, height[right_point] * (right_point - left_point));
                right_point--;
            }
        }
        return max_area;
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
