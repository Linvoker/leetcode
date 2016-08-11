//f(n) = max{n / 2, f(n / 2)} + max{n - n / 2, f(n - n / 2)}
//上面那个状态转移方程是错的,n == 8时并不适用.
//应该在大于6之后尽可能的将因子设置为3,至于为什么我也没搞懂
class Solution {
public:
    int integerBreak(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n == 4){
            return 4;
        } else if (n == 5) {
            return 6;
        } else if (n == 6) {
            return 9;
        } 
        else {
            return 3 * integerBreak(n - 3);
        }
    }
};
