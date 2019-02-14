#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {

    public:
        int reverse(int x) {
            long long int res = 0;
            while (x != 0) {
                res = res * 10 + (x % 10);
                x /= 10;
            }
            return INT_MIN <= res && res <= INT_MAX ? res : 0;
        }
        //用%/将数字从未到头放到string里，最后将string转换回来
        /* int reverse(int x) {
            if (x == 0) {
                return 0;
            }
            long long int tmp;
            string resStr = "";
            if (x < 0) {
                tmp = 0l-x;
                resStr = "-";
            } else {
                tmp = x;
            }
            //cout << "tmp: " <<  tmp << endl;
            int mod = 0;
            int cnt = 0;
            while (tmp != 0) {
                mod = tmp % 10;
                if (cnt != 0 || mod != 0) {
                    resStr.append(to_string(mod)); 
                    cnt++;
                }

                tmp /= 10;
            }
            //cout << resStr << endl;
            int res;
            try {
                res = stoi(resStr);
            } catch (const std::out_of_range& oor) {
                return 0;
            }
            return res; 
        } */
};
int main() {
    Solution x;
    cout << -2147483647 << " " << x.reverse(-2147483647) << endl;
    cout << 901000 << " " << x.reverse(901000) << endl;
    cout << 123 << " " << x.reverse(123) << endl;
    cout << -123 << " " << x.reverse(-123) << endl;
    cout << -120 << " " << x.reverse(-120) << endl;
    cout << 120 << " " << x.reverse(120) << endl;
}
