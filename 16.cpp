//见15题3sum
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        long long ret_val = INT_MAX;//long long防止16行ret_val - target时溢出
        for (int i = 0; i < nums.size() - 1; i++) {
            while (i != 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            int left_index = i + 1;
            int right_index = nums.size() - 1;
            int new_target = target - nums[i];
            while (left_index < right_index) {
                int comp = nums[left_index] + nums[right_index];
                ret_val = abs(ret_val - target) <= abs(nums[i] + comp - target) ? ret_val : nums[i] + comp;//判断谁与target的差距小ret_val就等于谁
                if (comp < new_target) {
                    left_index++;
                } else if (comp > new_target) {
                    right_index--;
                } else {
                    //left_index++;
                    //right_index--;
                    return ret_val;//换成这个可以使时间翻倍
                    
                }
               // while (left_index != i + 1 && nums[left_index] == nums[left_index - 1]) {
               //     left_index++;
                //} 
               // while (right_index != nums.size() - 1 && nums[right_index] == nums[right_index + 1]) {
               //     right_index--;
               // }
            }
        }
        return ret_val;
    }
};
