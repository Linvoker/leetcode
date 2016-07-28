//将x除以2，并让判断(x/2)^2大于还是小于x，以此二分搜索直到满足条件
//为防止int乘法溢出，可以使用除法或者long long类型
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) {
            return 1;
        } else {
            int min_val = 0;
            int max_val = x;
            int mid_val = x / 2;
            while (mid_val != min_val) {//当mid_val == min_val时，也许max_val == min_val == mid_val,异或许陷入永远的comp_val < x的循环
                unsigned long long comp_val = (unsigned long long) mid_val * mid_val;//避免计算两次乘法，注意要用longlong
                
                if (comp_val <  (unsigned long long)x ) {
                    min_val = mid_val;
                } else if (comp_val >  (unsigned long long)x){
                    max_val = mid_val;
                } else {
                    break;
                }
                
                mid_val = min_val + (max_val - min_val) / 2;//(max_val + min_val) / 2;
            }
            return mid_val;
        }
    }
};
