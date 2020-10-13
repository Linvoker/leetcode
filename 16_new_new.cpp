#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end()); //先排序
        int res = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) { //以nums[i]为第一个元素，不允许重复
                continue;
            }
            int j = i + 1, k = nums.size() - 1; //双指针j、k，初始值从i+1到size-1开始，分别指向第二个元素和第三个元素，根据和的大小 右移j或者左移i或者同时左移右移
            while (j < k) {
                if (abs(nums[j] + nums[k] + nums[i] - target) < min_val) {
                    min_val = abs(nums[j] + nums[k] + nums[i] - target);
                    res = nums[j] + nums[k] + nums[i];
                }
                if (nums[j] + nums[k] + nums[i] < target) {
                    j++;
                } else if (nums[j] + nums[k] + nums[i] > target) {
                    k--;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums = {1,1,1,1};
    cout << (new Solution)->threeSumClosest(nums, 0) << endl;
}
