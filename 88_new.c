#include <string.h>
#include <stdio.h>
//先将nums1平移到尾部，在从小到大往前塞，88.cpp的方法更好，不平移，直接从尾到首从大到小比较
void merge(int* nums1, int m, int* nums2, int n) {
        //O(n)
        memmove(nums1 + n, nums1, m * sizeof(int));
        
        int i = n, j = 0, pos = 0;
        while(i < n + m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums1[pos] = nums1[i];
                i++;
            } else {
                nums1[pos] = nums2[j];
                j++;
            }
            pos++;
        }
        
        if (i == n + m) {
            memmove(nums1 + pos, nums2 + j, (n - j) * sizeof(int));
        }
}
int main() {
    int n = 5, m = 1;
    int nums1[6] = {4, 0,0,0,0, 0};
    int nums2[5] = {1, 2, 3, 5, 6};

    merge(nums1, m, nums2, n); 
    return 0;
}
