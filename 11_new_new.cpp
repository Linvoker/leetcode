#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_val = 0;
        while (i < j) {
           if (height[i] > height[j]) {
                max_val = max(max_val, height[j] * (j - i));
                j--;
           } else {
                max_val = max(max_val, height[i] * (j - i));
                i++;
           }
        }
        return max_val;
    }
};
