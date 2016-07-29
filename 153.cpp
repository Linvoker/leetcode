//参考33.Search in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int comp = nums[right];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= comp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
