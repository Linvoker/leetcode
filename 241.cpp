//听说用动态规划更快


//递归，找到所有可能的结果放入指定vector里，每次递归依次遍历，找到+-*，则以+-*为分界，找到左边所有可能的结果并找到右边所有可能的结果
//，两个vector遍历做运算，并放入新的当前作为递归返回的vector。如果没找到+-*（用count判断），则说明当前递归该返回了，返回将stoi()push_back()进当前vector
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret_vec;
        helper(input, ret_vec, 0, input.size() - 1);
        return ret_vec;
    }
    void helper(string input, vector<int> &nums, int left_index, int right_index) {
        if (left_index > right_index) {//第一个字符是‘-’的情况
            return nums.push_back(0);
        }
        int count = 0;//用计数器判断是否进入循环里的if（）语句，如果没有则说明此子串没有+-*,直接将子串转换成int就好
        for (int i = left_index; i <= right_index; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                count++;
                vector<int> temp1;
                helper(input, temp1, left_index, i - 1);
                vector<int> temp2;
                helper(input, temp2, i + 1, right_index);
                for (auto v1 : temp1) {
                    for (auto v2 : temp2) {
                        if (input[i] == '+') {
                            nums.push_back(v1 + v2);    
                        }
                        else if (input[i] == '-') {
                            nums.push_back(v1 - v2);
                        } else {
                            nums.push_back(v1 * v2);
                        }
                        
                    }
                }        
            }
        }
        if (count == 0) {//终止条件
            string exchange = input.substr(left_index, right_index - left_index + 1);//第二个参数是要裁剪的个数
            nums.push_back(std::stoi(exchange));
        }
    }
};
//别人的做法（思路一样，但更简单容易理解）
//使用string::substr()裁剪成子串
/*class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(input.size() ==0) return {};
        vector<int> result;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i]!='+' &&input[i]!= '-' &&input[i]!= '*') continue;
            auto vec1 = diffWaysToCompute(input.substr(0, i));
            auto vec2 = diffWaysToCompute(input.substr(i+1));
            for(auto val1: vec1)
            {
                for(auto val2: vec2)
                {
                    if(input[i]=='+') result.push_back(val1+ val2);
                    else if(input[i]=='-') result.push_back(val1 - val2);
                    else if(input[i]== '*') result.push_back(val1 * val2);
                }
            }
        }
        return result.empty()?vector<int>{stoi(input)}:result;
    }
};
