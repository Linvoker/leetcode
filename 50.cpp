//没说限时却Time Limit Exceeded
/*class Solution {
public:
    double myPow(double x, int n) {
        
        if (n == 0) {
            return x;
        }
        double temp = x;
        while (--n) {
            x *= temp;
            
        }
        return x;
    }
};*/
//思路1：递归，要想得到myPow(x, n)首先要得到myPow(x, n/2),再作平方即可。T(n) = T(n/2) + O(1); 满足master theorem的case 2，即时间复杂度为O(lgn)
/*class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {//特例
            return 1;
        }
        if (n < 0) {//特例
            x = 1 / x;
            if (n == INT_MIN) {//int类型不能存放下INT_MIN的绝对值，只能单独拿出来考虑
                return x * myPow(x, INT_MAX);
            } else {
                n = -n;
            }
        }
        
        if (n == 1) {//终止条件
            return x;
        }
        
        double temp = myPow(x, n / 2);
        return n % 2 == 0 ? temp * temp : temp * temp * x;//考虑n为奇数
    }
};*/
//思路2：递归，myPow(x, n)就是myPow(x * x, n / 2),T(n) = T(n/2) + O(1);所以时间复杂度也是O(lgn)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {//特例
            return 1;
        }
        if (n < 0) {//特例
            x = 1 / x;
            if (n == INT_MIN) {//int类型不能存放下INT_MIN的绝对值，只能单独拿出来考虑
                return x * myPow(x, INT_MAX);
            } else {
                n = -n;
            }
        }
        
        if (n == 1) {//终止条件
            return x;
        }
        return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);//考虑n为奇数
    }
};



