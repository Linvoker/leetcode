#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int beg = 0;
        int end = nums.size() - 1;
        int pos = end - k + 1;
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
        return nums[pos];
    }
    //Hoare O(n)
    int partition(vector<int>& nums, int beg, int end) {
        if (beg >= end) {
            return beg;
        }
        /*----三数取中 可以到8ms------*/
        int mid = beg + ((end - beg) >> 1);
        if (nums[beg] < nums[mid]) {
            swap(nums[beg], nums[mid]);
        }
        if (nums[beg] > nums[end]) {
            swap(nums[beg], nums[end]);
        }
        if (nums[beg] < nums[mid]) {
            swap(nums[beg], nums[mid]);
        }
        /*----三数取中------*/

        int i = beg, j = end + 1; //遍历范围为beg+1 ~ end
        int pivot = nums[i];

        while (1) {
            while (nums[++i] < pivot) {
                if (i == end) break;
            }
            while (nums[--j] > pivot) {
                if (j == beg) break;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
            } else {
                break;
            }
        }
        swap(nums[j], nums[beg]);
        return j;
    }
    // pivot = 3
    // 3,7,5,8,1,4
    // i           j
    //   i     j  //ij都递增递减到合适的位置
    //   <----->
    // 3,1,5,8,7,4
    //   j i  //ij都递增递减到合适的位置
    // <->
    // 1,3,5,8,7,4

    /*
    int findKthLargest(vector<int>& nums, int k) {
        int i = nums.size() - k;
        nth_element(nums.begin(), nums.begin() + i, nums.end());
        return nums[i];
    }
    */
    // 堆 O(n+k*logn)
    /*int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int i = 0;
        while (i <= k - 1) {
            pop_heap(nums.begin(), nums.end() - i);
            i++;
        }
        return nums[nums.size() - i];
    }*/
};
int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5};
    (new Solution)->findKthLargest(nums, 3);
}
