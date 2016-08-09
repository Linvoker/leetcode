//先用回溯试试看,超时了
//题目没有要求找到能到达尾部的一个序列,只要求判断,所以用贪心算法来做
//看起来这个回溯很像贪心,但其实每步都直接跳步索引的值(虽然是最大值),但其是根本没做任何决定,不能算是最贪心的做法
/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        return backTracking(nums, 0);
    }
    bool backTracking(vector<int> &candidates, int begin) {
        if (begin == candidates.size() - 1) {
            return true;
        }
        if (begin >= candidates.size() - 1) {
            return false;
        }
        int step = candidates[begin];
        for (; step > 0 ; step--) {
            //没有剪枝函数
            if (backTracking(candidates, begin + step) == false) {
                continue;
            } else {
                return true;
            }
            
        }
        return false;
    }
};*/
//看答案的
//一步步遍历,每走一步用一个变量farthest来记录当前能到达的最远位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size() && farthest < nums.size() - 1 && i <= farthest; i++) {
            farthest = std::max(farthest, i + nums[i]);
        }
        return farthest >= nums.size() - 1;
    }
    
};
