//见26. Remove Duplicates from Sorted Array
//283. Move Zeroes都是一类问题

//我想到的复杂办法，逻辑很混乱但通过了
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int count = 0;
        int i = 1;
        while (i <= nums.size() - 1) {
            if (nums[i] == nums[i - 1]) {
                nums[i - count] = nums[i];
                while (nums[i] == nums[i - 1]) {
                    i++;
                    count++;
                    if (i == nums.size()) {
                        break;
                    }
                }
                count--;
            } else {
                nums[i - count] = nums[i];
                i++;
            }
        }
        return nums.size() - count;
    }
};*/
//标准答案，很伟大的想法,详见26题
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto v : nums) {
            if (i < 2 || v > nums[i - 2]) {
                nums[i++] = v;
            }
        }
        return i;
    }
};

