//先用二分查找找到那个轴（最小值）是一个好办法
//思路1：找到最小值后直接在此基础上二分查找整个数组，但写完之后发现很难考虑全面，而且看起来很复杂
//思路2：稍微改进以下可以更简单（/*里的是思路1），用lower_bound()改进，不直接再整个数组上操作，而是将数组分成两部分来二叉搜索。时间复杂度一样都为O(lgn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int comp = nums.back();
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {//退出循环后begin是轴右侧第一个值的索引（即最小值）
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > comp) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
            /*int add_num;
            if (begin == 0) {//vector并没有旋转（以0索引为旋转轴）//
                add_num = 0;
            } else {
                add_num = nums[begin - 1];//轴的左侧第一个值
            }
            
            begin = 0;
            end = nums.size() - 1;
            while (begin <= end) {//等效于lower_bound()，找到>=target的第一个数的索引
                int mid = begin + (end - begin) / 2;
                //+1是为了防止出现nums[mid]==0的情况而出现重复add_num
                if ((nums[mid] < nums[0] ? (nums[mid] + add_num + 1) : nums[mid]) >= (target < nums[0] ? (target + add_num + 1) : target)) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            if (begin == nums.size()) {//有可能target最大
                return -1;
            } else if (nums[begin] == target) {
                return begin;
            } else {
                return -1;
            }*/
            auto it1 = lower_bound(&nums[0], &nums[begin], target);
            auto it2 = lower_bound(&nums[begin], &nums[nums.size()], target);
            if (*it1 == target) {
                return it1 - &nums[0];
            } else if (*it2 == target) {
                return it2 - &nums[0];
            } 
            else {
                return -1;
            }
        
    }
};
