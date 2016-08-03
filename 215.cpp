//顺序统计量的最重要一题！

//直接用std::nth_element()，见169题
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>()) ;
        return nums[k - 1];
    }
};*/
//下面是nth_element()我的实现（快排为基础）
//看起来这题的test case里有很多升序降序，很少重复元素。因为固定枢轴快排330ms，而三数取中12ms，三数取中对重复元素还是很慢的
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return selectKthLagest(nums, 0, nums.size() - 1, k);
    }
    int selectKthLagest(vector<int> &nums, int low, int high, int k) {
        if (low == high) {
            return nums[low];
        }
        int i = partition(nums, low, high);//返回主元的索引，这个索引的值不会随着partition()的继续调用而改变
         
        if (i - low == k - 1) {
            return nums[i];
        } else if (i - low  < k - 1) {
            return selectKthLagest(nums, i + 1, high, k - (i - low) - 1);
        } else {
            return selectKthLagest(nums, low, i - 1, k);
        }
        
        
    }
    int partition(vector<int> &nums, int low, int high) {//返回主元的索引
        int i = low;
        int j = low;
        int mid = low + ((high - low) >> 1);
        if (nums[low] < nums[high]) {//三数取中
            if (nums[low] > nums[mid]) {
                swap(nums[low], nums[high]);
            } else if (nums[high] > nums[mid]) {
                swap(nums[mid], nums[high]);
            }
        } else {
            if (nums[low] < nums[mid]) {
                swap(nums[low], nums[high]);
            } else if (nums[high] < nums[mid]) {
                swap(nums[mid], nums[high]);
            }
        }

        while (j <= high) {
            if (nums[j] <= nums[high]) {
                j++;
            } else {
                std::swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
        std::swap(nums[i], nums[high]);
        return i;
    }
};*/
//再试试堆排序（最大堆）O(nlgn)
//如果make_heap()没有第三个参数，则构建的是最大堆，搭配的sort_heap()也不写第三个参数（可以写less<int>(),这是默认参数），它俩配合排序的是升序的。
//如果make_heap()有第三个参数greater<int>()这个函数，那么是在构建最小堆，而搭配的sort_heap()也一定要传递greater<int>()参数，才会是降序的
//这两个默认第三个参数都是less<int>()。
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end(),std::greater<int>());//O(n)构建最小堆
        std::sort_heap(nums.begin(), nums.end(),std::greater<int>());//O(nlgn)从大到小排列
        return nums[k - 1];
    }
};*/

//去掉堆排序的多余部分，不完全sort_heap,只sort到第k-1位最坏时间复杂度为O(n + klgn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end(), std::less<int>());//构建最大堆O(n)
        
        int ret_val;
        while (k--) {
             ret_val = nums[0];
             std::swap(nums[0], nums[nums.size() - 1]);
             nums.resize(nums.size() - 1);//这会改变vector的大小，和普通堆排序不一样
             adjust_heap(nums, 0);
            
        }
        return ret_val;
        
    }
    void adjust_heap(vector<int> &nums, int i) {//递归或者迭代都行，这里为了方便就用递归了
        int largest = i;
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;
        
        if (left_index + 1 <= nums.size() && nums[i] < nums[left_index]) {//i与其左孩子比较,这里要注意和算导书上不同，不能写成left_index <= nums.size() - 1,因为我一直再resize(),最后nums.size()很有可能变成了0，那么nums.size()这个正整数-1会溢出，下同
            largest = left_index;
        } 
        if (right_index + 1 <= nums.size() && nums[right_index] > nums[largest]) {//右孩子与暂时的最大结点比较
            largest = right_index;
        }
        if (largest != i) {
            std::swap(nums[largest], nums[i]);
            adjust_heap(nums, largest);
        }
        return;
    }
};
//利用优先队列来解决std::priority_queue<int>
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> q_int(nums.begin(), nums.end());
        int ret_val;
        while (k--) {
            ret_val = q_int.top();
            q_int.pop();
        }
        return ret_val;
    }
};
