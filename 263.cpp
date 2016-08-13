//3^x * 5^y 永远不可能得到偶数,而2^z 和前面两个相乘永远不可能得到奇数,所以一个奇数要想是ugly number必须由3,5组成不能包括2这个因子,
//一个偶数要想是ugly number,必须一直除以2直到n变为1返回true或者n变为奇数,判断这个奇数是否是一个ugly number
//上面复杂了,其实只需要将num整除至1,能成功就返回true,不成功就返回false
class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) {//边界条件
            return true;
        }
        if (num <= 0) {//边界条件
            return false;
        }
        
        if (num % 2 == 0) {
            return isUgly(num / 2);
        } else if (num % 3 == 0) {
            return isUgly(num / 3);
        } else if (num % 5 == 0) {
            return isUgly(num / 5);
        } else {
            return false;
        }
    }
};
