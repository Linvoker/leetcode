class Solution {
public:
    int findMin(vector<int>& nums) {
        int comp = nums.back();
        int low = 0;
        int high = nums.size() - 1;
        
        for (; nums[low] == nums[high] && low != high + 1; low++) {//预防{0,0,0,0...}因为解引用nums.end()会返回nullptr（即0）,这样早就越界了
        }
        
        while (low <= high) {//退出循环后begin是>=现轴右侧第一个值（即最小值）的索引
            int mid = low + (high - low) / 2;
            if (nums[mid] > comp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            } 
        }
        return low == nums.size() ? nums[low - 1] : nums[low];
    }
};
