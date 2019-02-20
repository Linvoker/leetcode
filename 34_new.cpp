#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    //典型的二分查找(左边界、右边界) 这两种是标准的写法
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int> {-1, -1};
        }
        if (nums.size() == 1) {
            return nums[0] == target ? vector<int> {0, 0} : vector<int> {-1, -1};
        }
        //先找上界 背下来
        int start = 0, end = nums.size(); //注意end是啥
        int mid;
        while (start < end) {
            mid = start + ((end - start) >> 1);
            if (nums[mid] < target) {
                start = mid + 1; //只加start的原因是mid是向下取整，如果用end = mid - 1的话会进死循环
            } else {
                end = mid;
            }
        }
        vector<int> ret{};
        if (nums[start] != target) {
            ret = vector<int>{-1, -1};
            return ret;
        } else {
            ret.push_back(start);
            cout << start << endl;
        }

        //再找下界 背下来
        start = 0;
        end = nums.size();
        while (start < end) {
            mid = start + ((end - start) >> 1);
            if (nums[mid] <= target) {
                start = mid + 1; 
            } else {
                end = mid;
            }
        }
        //结果在end - 1
        if (nums[end - 1] != target) {
            cout << "shit:" << end - 1 << nums[end - 1] << endl; //不会走到这
        } else {
            ret.push_back(end - 1);
            cout << end - 1 << endl;
        }
        return ret;

    }
};
int main () {
    Solution x;
    vector<int> nums{2,2};
    //vector<int> nums{5,7,7,8,8,10};
    //vector<int> nums{1,2,4,4,4,4,5,5};
    //vector<int> nums{3,1};
    //vector<int> nums{4,5,6,7,0,1,2};
    //vector<int> nums{7,8,9,0,1,2,3,4,5};
    //cout << x.searchRange(nums, 4) << endl;
    x.searchRange(nums, 3);
}
