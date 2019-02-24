#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //42.cpp的两边向中间靠的思路更好
    //这里用的是从左往右
    int trap(vector<int>& height) {
        int size = height.size();
        int max_size = 0;
        int i = 0;
        while (i < size) {
            int j = i + 1;
            int s = 0;//以i为左边界的槽的面积
            int dummy = 0;//假的面积(如果右边有高度大于i的高度，dummy面积就是i右边的注水面积
            int mark = -1;
            int max_height = 0;
            int a_s = 0;
            while (j < size) {
                if (height[j] >= height[i]) {
                    i = j;
                    s += dummy;
                    break;
                } else {
                    dummy += height[i] - height[j];
                }

                if (max_height < height[j]) { //如果当前i高度大于右边所有，则找到右边最高的拿一根算面积
                    mark = j; //右边最高的索引
                    a_s = dummy - (height[i] - height[j]) * (j - i); //面积
                    max_height = height[j]; //高度
                }
                j++;
            }
            max_size += s;
            if (j == size) {
                if (a_s == 0) {
                    i++;
                } else {
                    max_size += a_s;
                    i = mark;
                }
            }
        }
        return max_size;
    }
};
int main () {
    Solution x;
    //vector<int> shit{4,2,3};
    vector<int> shit{0,7,1,4,6};
    cout << x.trap(shit) << endl;
}
