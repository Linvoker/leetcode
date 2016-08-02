//用了额外的空间，其实不必的。
/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret_vec;
        int i = 0;
        int j = 0;
        while (i <= m - 1 && j <= n - 1) {
            if (nums1[i] < nums2[j]) {
                ret_vec.push_back(nums1[i]);
                i++;
            } else {
                ret_vec.push_back(nums2[j]);
                j++;
            }
        }
        if (i != m) {
            for (; i <= m - 1; i++) {
                ret_vec.push_back(nums1[i]);
            }
        } else {
            for (; j <= n - 1; j++) {
                ret_vec.push_back(nums2[j]);
            }
        }
        nums1 = ret_vec;
        return;
    }
};*/
//nums1和nums2在最开始已经分配好了空间，利用这一点可以从尾到头地放置
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m >= 1 || n >= 1) {
            nums1[m + n - 1] = n < 1 || (m >= 1 && nums1[m - 1] >= nums2[n - 1]) ? nums1[--m] : nums2[--n];
        }
    }
};

