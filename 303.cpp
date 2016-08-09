//有几点要注意:1.vector在没有push_back()到某个位置的元素是不能用operator[]给他赋值,因为此时[]的操作是未定义的,算是越界.
//2.思路就是建立一个数组在i的位置存放0-i的sum,这样计算范围内的值就不用一步一步做多个加法了.直接一个减法就搞定.
//唯一跟动态规划扯上关系的大概就是用表sum_vec来存放重复子结构了,状态转移方程:sumRange(i, j) = sum_vec(j) - sum_vec(i - 1)
class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }
        sum_vec.push_back(nums[0]);//
        for (int i = 1; i <= nums.size() - 1; i++) {
            sum_vec.push_back(sum_vec[i - 1] + nums[i]); 
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sum_vec[j];
        } else {
            return sum_vec[j] - sum_vec[i - 1];
        }
    }
private:
    vector<int> sum_vec;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
