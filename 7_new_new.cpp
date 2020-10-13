#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int ispos = 1;
        if (x < 0) {
            x = -x; 
            ispos = -1;
        }
        int res = 0;
        while (x > 0) {
            res = res * 10 + (x % 10); 
            x /= 10;
        }
        return res * ispos;
	}
};
int main() {
    cout << (new Solution)->reverse(9) << endl;
}
