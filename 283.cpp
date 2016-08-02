//和26. Remove Duplicates from Sorted Array是一类问题
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto v : nums) {
            if (v != 0) { //第一个指针的值不等于0时，赋值给此次应该被赋值的地点i。
                nums[i++] = v;
            } 
        }
        while (i <= nums.size() - 1) {
            nums[i++] = 0; 
        }
        return;
    }
};
