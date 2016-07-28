//std:lower_bound的用法
//二分查找
class Solution {
public:
        vector<int> searchRange(vector<int>& nums, int target) {
            
            auto lit=lower_bound(nums.begin(),nums.end(),target);
            auto rit=upper_bound(nums.begin(),nums.end(),target);
            --rit;
            if(*lit!=target)
                return {-1,-1};
            return {lit-nums.begin(),rit-nums.begin()};
        }
    };
//我的想法和大家不一样，我先用二分查找找到任意一个与target相等的位置，然后再向左向右同时移动知道!=target或者出界则退出，
//退出判断是否与target相等，若相等则i不变，不等则i+1，j-1
/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int min_index = 0;
        int max_index = nums.size() - 1;
        int mid_index = max_index / 2;
        while (min_index <= max_index) {
            if (target < nums[mid_index]) {
                max_index =  mid_index - 1;
            } else if (target > nums[mid_index]) {
                min_index = mid_index + 1;
            } else {
                break;
            }
            mid_index = max_index + (min_index - max_index) / 2; //(max_index + min_index) / 2 担心数字过大
        }
        if (min_index > max_index) {
            return vector<int> {-1, -1};
        } else {
            int i = mid_index, j = mid_index; 
            while (i != 0 && nums[i] == target || j != nums.size() - 1 && nums[j] == target) {
                if (nums[i] == target && i != 0) {
                    i--;
                }
                if (nums[j] == target && j != nums.size() - 1) {
                    j++;
                }
            }
            i = nums[i] == target ? i : i + 1;
            j = nums[j] == target ? j : j - 1;
            return vector<int> {i, j};
        }
    }
};
