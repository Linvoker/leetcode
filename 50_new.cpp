#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) {
            return x;
        } else if (n == 0) {
            return 1;
        }
        if (n < 0) {
            x = (double)1.0/x;
            if (n == INT_MIN) {//特例: 无法将INT_MIN的相反数放入int类型
                return x * myPow(x, INT_MAX);
            } else {
                n = -n;
            }
        }
        double t = myPow(x, n/2);
        if (n % 2 == 0) {
            return t * t;
        } else {
            return t * t * x;
        }
    }
};
int main() {
    //cout << (new Solution)->myPow(4, -3) << endl;
    cout << (new Solution)->myPow(34.00515, -3) << endl;
}
