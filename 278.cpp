// Forward declaration of isBadVersion API.

//这题只是考察怎么算mid不会溢出而已
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            //int mid = ((long)low + high) / 2;
            int mid = low + (high - low) / 2;
            int mid = (low + high) >> 1;
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
