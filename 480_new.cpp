#include<vector>
#include<iostream>
#include<set>

using namespace std;
class Solution {
public:
    //[1,3,-1,-3,5,3,6,7]
    //奇数: 
    //增: i > m: m++ 1️⃣
    //删: i <= m: m++ 2️⃣
    //
    //偶数:
    //增: i < m: m-- 3️⃣
    //删: i > m || i == m && i在multiset里是最左边的i值(将会被删掉): m-- 4️⃣
    //
    //若k为奇数,1️⃣  => 4️⃣
    //若k为偶数,3️⃣  => 2️⃣
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mi(nums.begin(), nums.begin() + k);
        vector<double> res;

        auto it = next(mi.begin(), k / 2);
        int isEven = 1 - k % 2;

        for (int i = k; i < nums.size(); i++) {
            if (isEven) {
                res.push_back((((double)(*it)) + *(prev(it, 1))) / 2);
            } else {
                res.push_back((double)*it);
            }

            mi.insert(nums[i]);
            if (!isEven) { //奇数
                if (nums[i] >= *it) it++;
                if (nums[i - k] > *it || (nums[i - k] == *it && *it != *next(it, -1))) it--;
            } else {
                if (nums[i] < *it) it--;
                if (nums[i - k] <= *it) it++;
            }
            mi.erase(mi.lower_bound(nums[i - k])); //不能直接erase，会删除多个元素
        }
        res.push_back((((double)(*it)) + *(prev(it, isEven))) / 2);
        return res;
    }
};
int main() {
    vector<int> nums = {1,-1,-1,3,5,6};
    //vector<int> nums = {2,2,2,2,1,2,2,2,2};
    //vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483646,2147483647,2147483647,2147483647,2147483647};
    auto ret = (new Solution)->medianSlidingWindow(nums, 3);
    return 0;
}
