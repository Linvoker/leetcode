//思路1：sort()之后遍历计数，时间复杂度为O(nlgn)
//不过不用这么愚蠢，因为存在次数大于n/2说明排序后第n/2个元素一定会是majority()。{1,1,1,2,3,(4)}
//可以用算法导论上的顺序统计量概念来做，以快排为模型的计算顺序统计量方法时间复杂度为O(n)。红黑树的扩展方法时间复杂度为O(lgn)，但这里不适用
//std::nth_element(iterator, iterator begin() + (nth - 1), itreator),第n小的元素在nums[nth]上
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nth = nums.size() / 2;
        std::nth_element(nums.begin(), nums.begin() + nth - 1, nums.end());
        return nums[nth];
    }

};
//思路2：hashtable（unordered_map<int, int>）来做 时间复杂度为O(n)40ms
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m_int_int;
        for (auto v : nums ) {
            if (m_int_int[v] < nums.size() >> 1) {
                ++m_int_int[v];
            } else {
                return v;
            }
        }
        return -1;
    }
};
//思路3：用题目要求的分治法来做（递归）时间复杂度为O(n),20ms
//左半边的majority和右半边的majority相等则递归返回左半边的majority
//如果左右majority不等，则返回在此大范围内majority出现次数较多的那个（小范围可能会一样多，但最后完全返回时不可能一样多，因为majority的次数会>n/2，两个的个数同时大于总数的一半是不可能的）
//终止条件是low == high，递归返回nums[low]
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
    int majority(vector<int> &nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        int mid = low + ((high - low) >> 1);
        int left_maj = majority(nums, low, mid);
        int right_maj = majority(nums, mid + 1, high);
        if (left_maj == right_maj) {
            return left_maj;
        } else {
            return count(nums.begin() + low, nums.begin() + high + 1, left_maj) > count(nums.begin() + low, nums.begin() + high + 1, right_maj)
                    ? left_maj : right_maj;
        }
    }
};
