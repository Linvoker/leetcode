#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0, end = nums.size(), mid = 0;
        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (nums[mid] < target) {
                beg = mid + 1; 
            } else {
                end = mid;
            }
        }

        // 1,2,3   5
        // 1,2,5   4
        // 1,2,3   0
        if (beg == nums.size() || nums[beg] != target) {
            return vector<int> {-1, -1};
        }
        int minPos = beg;
        //cout << minPos << endl; 
        
        beg = 0; end = nums.size(); mid = 0;
        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (nums[mid] <= target) {
                beg = mid + 1; 
            } else {
                end = mid;
            }
        }
        //cout << beg << endl;
        return vector<int> {minPos, beg - 1};
    }
};
int main() {
    vector<int> nums = {5,7,7,8,8,10};
    (new Solution)->searchRange(nums, 11);
}
