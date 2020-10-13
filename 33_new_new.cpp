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
        cout << beg << endl;

        if (target <= nums[nums.size() - 1]) {
            end = nums.size();
        } else {
            beg = 0;
        }

        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return beg < nums.size() && nums[beg] == target ? beg : -1;
    }
};
int main () {
    vector<int> nums{
            1,1,3,1
    };
    cout << (new Solution())->search(nums, 3) <<endl;
}
