#include<vector>
#include<iostream>
//#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
        //投票法
    int majorityElement(vector<int>& nums) {
        int prev, cnt = 0;
        for (auto num : nums) {
            if (cnt == 0) {
                prev = num;
                cnt++;
            } else if (num != prev) {
                cnt--;
            } else {
                cnt++;
            }
        }
        return prev;
    }
    /*
    int majorityElement(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        //nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        //return nums[nums.size() / 2];
        //random_shuffle(nums.begin(), nums.end());
        findNthEle(nums, nums.size() / 2);
        return nums[nums.size() / 2];
    }
    void findNthEle(vector<int>& nums, int pos) {
        int beg = 0;
        int end = nums.size() - 1;
        while (1) {
            int ret = partition(nums, beg, end);
            if (ret < pos) {
                beg = ret + 1;
            } else if (ret > pos) {
                end = ret - 1;
            } else {
                break;
            }
        }
    }
    //这种快排在有大量重复元素时会升至O(n^2)，可以使用三路快排，把与pivot相等的元素丢到中间。
    int partition(vector<int>& nums, int beg, int end) {
        if (beg >= end) {
            return beg;
        }
        int pivot = nums[beg];

        while (beg < end) {
            while (beg < end && nums[end] >= pivot) { //等于的时候不处理
                end--;
            }
            nums[beg] = nums[end];
            //beg++;
            while (beg < end && nums[beg] <= pivot) { //等于的时候不处理
                beg++;
            }
            nums[end] = nums[beg];
            //end--;
        }
        nums[beg] = pivot;
        return beg;
    }
    */


    // pivot = 3
    // 3,7,5,8,1,4 //先遍历j
    // i         j // nums[j] >= pivot j--
    // i       j   //nums[j] < pivot => 交换ij 接下来遍历i
    // <--------
    // 1,7,5,8,1,4
      // i     j  //num[i] > pivot =>交换ij 接下来遍历j
      // ------>
    // 1,7,5,8,7,4
      // i   j    // nums[j] >= pivot j--
    // 1,7,5,8,7,4
     // i(j)      //退出循环nums[i] = pivot
    // 1,3,5,8,7,4
};
int main () {
    vector<int> data {-1,1,1,1,2,1};
    cout << (new Solution)->majorityElement(data) << endl;
}
