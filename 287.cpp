
//限制了空间复杂度就不能用hashtable了
//直接用两个指针会花费n + (n - 1) + (n - 2) + ...+ 1的时间，即为O(n^2),不可取
//那么直接先sort()排序O(nlgn),再用两个指针遍历。这样会破坏数组结构，题目不允许，也不可取

//思路1：二叉搜索（数组不需要有序，因为不是搜索特定的值），此题是二叉搜索无序数组的典型！！O(nlgn)
//还有一个思路我不想看。。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;//最小值
        int high = nums.size() - 1;//最大值
    
        while (low <= high) {//O(lgn)
            int mid = low + (high - low) / 2;//中间的数
            
            int count = 0;
            for (auto v : nums) {//O(n)
                if (v <= mid) {
                    count++;
                }
            }
            if (count <= mid) {//小于等于说明重复的值比mid大(存在小于是因为可能不只有两个复制品)
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
