#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        } else if (nums.empty()) {
            return -1;
        }
        int start = 0, end = size - 1;
        int mid = (start + end) / 2;
        if (nums[start] > nums[end]) {
            //找左中枢

            while (start < end) {
                if (nums[mid] > nums[mid + 1]) {
                    break;
                }
                if (nums[mid] > nums[start]) { //中枢在右边
                    start = mid;
                    mid = (mid+end) / 2;
                } else if (nums[mid] < nums[end]) {//中枢在左边
                    end = mid;
                    mid = (start+mid) / 2;
                }
            }
            //cout << "mid:" << mid << endl;
            // if (nums[mid] <= nums[mid + 1]) {
                // return -2;//给的数组不合法
            // }
            if (target >= nums[0]) {
                start = 0;
                end = mid;         
            } else if (target <= nums[size - 1]) {
                start = mid + 1;
                end = size - 1;
            }
        }


        while(start < end) {
            mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1; 
            } else {
                end = mid;
            }
        }
        return nums[end] == target ? end : -1;

        //return mid;
    }
};
int main () {
    Solution x;
    //vector<int> nums{7,8,0};
    vector<int> nums{3,1};
    //vector<int> nums{4,5,6,7,0,1,2};
    //vector<int> nums{7,8,9,0,1,2,3,4,5};
    cout << x.search(nums, 3) << endl;
}
