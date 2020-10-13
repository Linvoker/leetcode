#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    //先找到中轴点O(logn)，再二分找中轴点左边或右边O(logn)
    //5,6,7,8,1,2
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {return -1;}
        int beg = 0, end = nums.size() - 1, mid = 0;
        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (nums[mid] <= nums[nums.size() - 1]) {
                //中轴线在左边或当下
                end = mid;
            } else {
                //中轴线在右边
                beg = mid + 1;
            }
        }
        return nums[beg];
    }
};
