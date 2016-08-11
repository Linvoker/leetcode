//这题有点像回溯的结构,但是不要往回溯的框架上套,顺其自然根据状态转移方程:f(target) = f(target - nums[1]) + f(target - nums[2]) +...f(target - nums[n])
//再将重叠的子问题用table保存起来即可
/*class Solution {
public:
    typedef int TargetType;
    typedef int CountType;
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<TargetType, CountType> table;
        return dp(nums, target, table);
    }
    int dp(vector<int> &nums, int target,  unordered_map<TargetType, CountType> &table) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(target - nums[i]) == table.end()) {//如果不在table里
                table[target - nums[i]] = dp(nums, target - nums[i], table);
            }
            count += table[target - nums[i]];
        }
        return count;
    }
};*/
//用数组取代unordered_map会快很多,省去了hash函数的时间
class Solution {
public:
    typedef int TargetType;
    typedef int CountType;
    int combinationSum4(vector<int>& nums, int target) {
        //unordered_map<TargetType, CountType> table;
        vector<int> table(target, -1);
        return dp(nums, target, table);
    }
    int dp(vector<int> &nums, int target, vector<int> &table) {
        if (target == 0) {
            return 1;
        }
        /*if (target < 0) {
            return 0;
        }*/
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] < 0) {//多了这一句代替上面的<0的情况,因为数组担心越界而hashmap不会
                continue;
            } else if (table[target - nums[i]] == -1) {//如果不在table里
                table[target - nums[i]] = dp(nums, target - nums[i], table);
            }
            count += table[target - nums[i]];
        }
        return count;
    }
};
