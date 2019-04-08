#include<vector>
#include<iostream>
//#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
#include<vector>
#include<iostream>
//#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
    //投票法
    /*int majorityElement(vector<int>& nums) {
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
    }*/

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
    /*
    //Lomuto
    int partition(vector<int>& nums, int beg, int end) {
        if (beg >= end) {
            return beg;
        }
        int pivot = nums[end];
        int i = beg;
        for (int j = beg; j < end; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[end]);
        return i;
    }
    // pivot = 4
    // 3,7,5,8,1,4
    // ij
    //   ij
    //   i     j
    //   <----->
    // 3,1,5,8,7,4
    //     i     j
    //     <----->
    // 3,1,4,8,7,5
    */
    //Hoare
    int partition(vector<int>& nums, int beg, int end) {
        if (beg >= end) {
            return beg;
        }
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
};
int main () {
    //vector<int> data {-1,1,1,1,2,1};
    vector<int> data {4,5,4};
    cout << (new Solution)->majorityElement(data) << endl;
}
