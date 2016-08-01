//erase() complexity:Linear in distance between pos and the end of the container.
//利用这种方法 要删除的元素的后面的迭代器会失效，因为后面直到end()都会被重新排列，话费O(m)的时间复杂度,一共会花费O(n^2)平均时间复杂度
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        for (auto it1 = nums.begin(), it2 = nums.begin() + 1; it2 != nums.end(); ) {
            if (*it1 == *it2) {
                nums.erase(it2);
                it2 = it1 + 1;
            } else {
                ++it1;
                ++it2;
            }
        }
        return nums.size();
    }
};*/
//另一种方式来源于题目中的灵感：It doesn't matter what you leave beyond the new length. 
//将重复元素改成INT_MAX,再重新排列vector，最后只会话费O(nlgn)的平均时间复杂度
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int count = 0;
        for (auto it1 = nums.begin(), it2 = nums.begin() + 1; it2 != nums.end(); ++it1, ++it2) {
            if (*it1 == *it2) {
                *it1 = INT_MAX;
                count++;
            } 
        }
        sort(nums.begin(), nums.end());
        return nums.size() - count;
    }
};*/
//别人想的 最好的办法，使用O(n)时间复杂度
//不是把duplicate放在后面，而是慢慢把它们覆盖掉
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int count = 0;
            for(int i = 1; i <= nums.size() - 1; i++){
                if(nums[i] == nums[i-1]) count++;
                else nums[i-count] = nums[i];//覆盖掉原本的数组
            }
        return nums.size()-count;
    }
};
