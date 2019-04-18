class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        return isHappyHelper(n, us);
    }
    bool isHappyHelper(int n, unordered_set<int> &us) {
        if (n <= 0) {
            return false;
        }
        us.insert(n);
        int m = 0;
        while (n) {
            m += pow((n % 10), 2);
            n /= 10;
        }
        if (m == 1) {
            return true;
        } else if (us.find(m) != us.end()) {
            return false;
        } else {
            return isHappyHelper(m, us);
        }
    }
};
