//按照二分查找模板写，参考https://zh.wikipedia.org/wiki/H%E6%8C%87%E6%95%B0
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int c_size = citations.size();
        int low = 0;
        int high = c_size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] < c_size - mid) {//citations[mid]为引用次数，c_size - mid为有多少篇不少于这个引用次数
                low = mid + 1;
            } else if (citations[mid] > c_size - mid) {
                high = mid - 1;
            } else {
                return c_size - mid;
            }
        }
        return c_size - low;//返回篇数
    }
};
