#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    //动态规划的做法，时间复杂度按理说也是O(n)，但是却很耗时。用贪心算法比较靠谱(见55.cpp)
    bool canJump(vector<int>& nums) {
        vector<int> table(nums.size(), -1);
        return backtrack(nums, 0, table);
    }
    bool backtrack(vector<int>& nums, int idx, vector<int> &table) {
        if (idx >= (int)nums.size() - 1) {
            return true;
        }
        if (table[idx] == 0) {
            return false;
        }
        //for (int i = idx + 1; i <= nums[idx] + idx; i++) {
        for (int i = nums[idx] + idx; i > idx; i--) {
            if (backtrack(nums, i, table)) {
                return true;
            }
        }
        table[idx] = 0;
        return false;
    }
};
int main() {
    vector<int> nums{2,3,1,1,4};
    cout << (new Solution)->canJump(nums) << endl;
}
