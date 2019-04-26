#include<vector>
#include<iostream>
#include<deque>
#include<map>
//#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //维护一个双端队列，队列头放当前窗口的最大值（索引即可），单调递减，队尾放最小值
        //时间复杂度为啥是O(n)?
        deque<int> di;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) { //i指向窗口最右边
            if (!di.empty()) {
                if (i - k == di.front()) {
                    di.pop_front();
                }
                while (!di.empty() && nums[i] > nums[di.back()] ) {
                    di.pop_back();
                }
            }
            di.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[di.front()]);
            }
        }
        return res;
    }
        /*
    //O(lgk);
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return vector<int>();
        }
        map<int, int> m; //ele => count
        int i = 0, j = 0;
        vector<int> res;
        while (j <= nums.size()) {
            if (j < k) {
                m[nums[j]]++;
                j++;
                continue;
            }
            res.push_back(m.rbegin()->first);

            if (j == nums.size()) {
                break;
            }
            if (--m[nums[i]] == 0) {
                m.erase(nums[i]);
            }
            m[nums[j]]++;
            i++;j++;
        }
        return res;
    }
    */
};
int main() {
    vector<int> nums = {1,3,-1};
    int k = 3;
    auto res = (new Solution)->maxSlidingWindow(nums, k);
    return 0;
}
