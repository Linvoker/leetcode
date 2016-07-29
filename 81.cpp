//duplicate可能在原轴上1,1,2,3,1,1,1，也可能在现轴上3,4,4,1,1,2,3.现轴上无所谓，原轴上要讨论
//原轴上：从第一个不等于nums[end]的位置开始寻找 >=现轴右侧第一个值（即最小值）的索引

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int comp = nums.back();
        int begin = 0;
        int end = nums.size() - 1;
        
        for (; nums[begin] == nums[end] && begin != end + 1; begin++) {//预防{0,0,0,0...}因为解引用nums.end()会返回nullptr（即0）,这样早就越界了
        }
        
        while (begin <= end) {//退出循环后begin是>=现轴右侧第一个值（即最小值）的索引
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > comp) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            } 
        }
        
        auto it1 = lower_bound(nums.begin(), nums.begin() + begin, target);
        auto it2 = lower_bound(nums.begin() + begin, nums.end(), target);
        //auto it1 = lower_bound(&nums[0], &nums[begin], target);
        //auto it2 = lower_bound(&nums[begin], &nums[nums.size()], target);
        
        //判断是否为end()很重要，因为end()的解引用的值是零，target如果也是零就不好了,而这里可能传给lower_bound()的两个参数都是nums.end()
        if (it1 != nums.end() && *it1 == target || it2 != nums.end() && *it2 == target) {
            return true;
        } else {
            return false;
        }
    }
};
