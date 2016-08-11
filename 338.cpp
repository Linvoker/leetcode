//O(n * sizeof(int))一位一位数1的个数
/*class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret_vec;
        int count = 0;
        int temp = 0;
        for (int i = 0; i <= num; i++) {
            count = 0;
            temp = i;
            while (temp != 0) {
                if (temp % 2 == 1) {
                    count++;
                }
                temp >>= 1;
            }
            ret_vec.push_back(count);
        }
        return ret_vec;
    }
};*/
//可以很容易地发现规律,000,001,010,011,100,101,110,111.偶数的1的个数等于此数/2时的1的个数(移位而已),奇数的1的个数等于此数/2时的1的个数+1(移位并+1)
//f(n) = f(n / 2)n为偶数, f(n) = f(n / 2 + 1),n为奇数
//自顶向下并不科学,因为只能一半一半来,不能够把所有的n-1...0的1的个数都找出来
//用自底向上+hashtable(其实没必要用hashtable,反而因为hash函数而变慢了)
/*class Solution {
public:
    vector<int> countBits(int num) {
        unordered_map<int, int> table; 
        vector<int> ret_vec;
        
        for (int i = 0; i <= num; i++) {
            if (i == 0) {
                table[i] = 0;
            } else if (i % 2 == 0){
                table[i] = table[i >> 1];
            } else {
                table[i] = table[i >> 1] + 1;
            }
            ret_vec.push_back(table[i]);
        }
        return ret_vec;
    }
    
};*/
//自底向上+vector(这题的table不用随机插入,只需按序插入,没必要用hashtable)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> table; 
        vector<int> ret_vec;
        
        for (int i = 0; i <= num; i++) {
            if (i == 0) {
                table.push_back(0);
            } /*else if (i % 2 == 0){
                table.push_back(table[i >> 1]);
            } else {
                table.push_back(table[i >> 1] + 1);
            }*/
            else   table.push_back(table[i >> 1] + (i & 1));//用移位代替除法，用位掩码bitmask代替除余判断奇偶
            ret_vec.push_back(table[i]);
        }
        return ret_vec;
    }
    
};
