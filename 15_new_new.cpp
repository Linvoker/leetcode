#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    //时间复杂度O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>{};
        }
        sort(nums.begin(), nums.end()); //先排序
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) { //以nums[i]为第一个元素，不允许重复
                continue;
            }
            int j = i + 1, k = nums.size() - 1; //双指针j、k，初始值从i+1到size-1开始，分别指向第二个元素和第三个元素，根据和的大小 右移j或者左移i或者同时左移右移
            while (j < k) {
                if (nums[j] + nums[k] < -nums[i]) {
                    j++; 
                } else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    res.push_back(vector<int> {nums[i], nums[j], nums[k]}); 
                    while(j < k && nums[j] == nums[j + 1]) { //第二个元素去重
                        j++; 
                    }
                    while(j < k && nums[k] == nums[k - 1]) { //第三个元素去重
                        k--; 
                    }
                    j++;k--;
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums{
        0,0,0
    };
    (new Solution)->threeSum(nums);
}
