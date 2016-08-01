//此题的时间复杂度的lower bound是O(n^3)
//参看15题3sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<vector<int>> ();
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret_vec;
        int max_index = nums.size() - 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {//减少运行时间，避免这些情况进入循环浪费时间
                break;
            } else if (nums[i] + nums[max_index - 2] + nums[max_index - 1] + nums[max_index] < target) {
                continue;
            }
            
            if (i != 0 && nums[i] == nums[i - 1]) {//大循环消除重复元素
                continue;
            }
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {//减少运行时间，避免这些情况进入循环浪费时间
                    break;
                } else if (nums[i] + nums[j] + nums[max_index - 1] + nums[max_index] < target) {
                    continue;
                }
                
                if (j != i + 1 && nums[j] == nums[j - 1]) {//中循环消除重复元素
                    continue;
                }
                
                int new_target = target - nums[i] - nums[j];
                int left_index = j + 1;
                int right_index = nums.size() - 1;
                while (left_index < right_index) {
                    if (left_index != j + 1 && nums[left_index] == nums[left_index - 1]) {//小循环消除重复元素
                        left_index++;
                        continue;
                    }
                    if (right_index != nums.size() - 1 && nums[right_index] == nums[right_index + 1]) {
                        right_index--;
                        continue;
                    }
                    
                    int comp = nums[left_index] + nums[right_index];
                    if (comp < new_target) {
                        left_index++;
                    } else if (comp > new_target) {
                        right_index--;
                    } else {
                        ret_vec.push_back({nums[i], nums[j], nums[left_index], nums[right_index]});
                        left_index++;
                        right_index--;
                    }
                    
                    
                }
            }
        }
        return ret_vec;
    }
};
