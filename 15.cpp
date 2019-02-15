//利用两个指针完成扫描，利用2sum的思想借用hashmap解决,但这是错误的
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        } 
        vector<vector<int>> ret_vec;
        unordered_map<int, int> m_int_int;
        std::sort(nums.begin(), nums.end());
        for (auto v : nums) {
            ++m_int_int[v];//记录出现的次数
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            
            --m_int_int[nums[i]];//每次循环前让map删掉这个指针指着的元素
           // if (i != 0 && nums[i] == nums[i - 1]) {
           //     continue;
           // }
            for (int j = i + 1; j < nums.size() - 1; j++) {
                --m_int_int[nums[j]];//每次循环前让map删掉这个指针指着的元素
                //if (j != i + 1 && nums[j] == nums[j - 1]) {
                //    continue;
               // }
                
                if (m_int_int[0 - nums[i] - nums[j]] > 0) {
                    ret_vec.push_back({nums[i], nums[j], 0 - nums[i] - nums[j]});
                }
                
            }
        }
        return ret_vec;
    }
};*/
//先排序，然后一个一个遍历，利用两个指针一前一后 在每一个大循环过程中找到后面序列里相加等于-nums[i]的两个值
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        } 
        vector<vector<int>> ret_vec;
        std::sort(nums.begin(), nums.end());//先排序
        int max_index = nums.size() - 1;
        for (int i = 0; i < max_index; i++) {
            while (i != 0 && nums[i] == nums[i - 1]) {//大循环里避免重复元素
                i++;
            }
            
            int target = -nums[i];
            if (target < 0) {// 按升序排序好这种情况不可能有办法=0
                return ret_vec;
            }
            int left_index = i + 1;
            int right_index = max_index;
            while (left_index < right_index) { //用两端指针逼近即可
                
                if (nums[left_index] + nums[right_index] < target) {
                    left_index++;
                } else if (nums[left_index] + nums[right_index] > target) {
                    right_index--;
                } else {
                    ret_vec.push_back({nums[i], nums[left_index], nums[right_index]});
                    left_index++;
                    right_index--;
                }
                
                while (left_index != i + 1 && nums[left_index] == nums[left_index - 1]) {//小循环里避免重复元素
                    left_index++;
                }
                while (right_index != nums.size() - 1 && nums[right_index] == nums[right_index + 1]) {
                    right_index--;
                }
            }
        }
        return ret_vec;
     
    }
};
