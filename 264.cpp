//原理:https://discuss.leetcode.com/topic/21791/o-n-java-solution

//其实不用三个queue,只要6个int即可,三个记录queue的back(),三个记录各自queue的值所需要用到的ret_vec的值的索引.
/*class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ret_vec{INT_MIN, 1};//ret_vec[0]不存数
        queue<int> q1, q2, q3;
        q1.push(2);
        q2.push(3);
        q3.push(5);
        int count = 1;
        while(count <= n) {
            if (q1.front() <= q2.front() && q1.front() <= q3.front()) {
                if (addToVec(q1.front(), ret_vec)) {//如果ret_vec能够加入这个数(和之前加入进来的数不等),则更新3个queue
                    addToQueue(q1.front(), q1, q2, q3); 
                    count++;//计数器一定只能在ret_vec.size()增大1的前提下自增
                }
                q1.pop();
            } else if (q3.front() <= q2.front() && q3.front() <= q1.front()) {
                if (addToVec(q3.front(), ret_vec)) {
                    addToQueue(q3.front(), q1, q2, q3); 
                    count++;
                }
                q3.pop();
            } else {
                if (addToVec(q2.front(), ret_vec)) {
                    addToQueue(q2.front(), q1, q2, q3);  
                    count++;
                }
                q2.pop();
            }
        }
        return ret_vec[n];
    }
    bool addToVec(int val, vector<int> &ret_vec) {//和ret_vec.back()不等,则加入并返回true
        if (val == ret_vec.back()) {
            return false;
        } else {
            ret_vec.push_back(val);
            return true;
        }
    }
    void addToQueue(int val, queue<int> &q1, queue<int> &q2, queue<int> &q3) {
        q1.push(val * 2);
        q2.push(val * 3);
        q3.push(val * 5);
        return;
    }
};*/
//static dynamic programming,只会让测试一连串数据变得更快,对于一个nthUglyNumber(n)并不会更快
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ret_vec{INT_MIN, 1};//ret_vec[0]不存数
        deque<int> dq1 (1, 2);
        deque<int> dq2 (1, 3);
        deque<int> dq3 (1, 5);
        static queue<int> q1(dq1), q2(dq2), q3(dq3);//queue不是standard container,是一个container adapter,queue<int>只能用std::deque或者lstd::ist初始化
        //q1.push(2);
        //q2.push(3);
        //q3.push(5);
        if (ret_vec.size() - 1 >= n) {
            return ret_vec[n];
        }
        while(ret_vec.size() <= n) {
            if (q1.front() <= q2.front() && q1.front() <= q3.front()) {
                if (addToVec(q1.front(), ret_vec)) {//如果ret_vec能够加入这个数(和之前加入进来的数不等),则更新3个queue
                    addToQueue(q1.front(), q1, q2, q3); 
                }
                q1.pop();
            } else if (q3.front() <= q2.front() && q3.front() <= q1.front()) {
                if (addToVec(q3.front(), ret_vec)) {
                    addToQueue(q3.front(), q1, q2, q3); 
                }
                q3.pop();
            } else {
                if (addToVec(q2.front(), ret_vec)) {
                    addToQueue(q2.front(), q1, q2, q3);  
                }
                q2.pop();
            }
        }
        return ret_vec[n];
    }
    bool addToVec(int val, vector<int> &ret_vec) {//和ret_vec.back()不等,则加入并返回true
        if (val == ret_vec.back()) {
            return false;
        } else {
            ret_vec.push_back(val);
            return true;
        }
    }
    void addToQueue(int val, queue<int> &q1, queue<int> &q2, queue<int> &q3) {
        q1.push(val * 2);
        q2.push(val * 3);
        q3.push(val * 5);
        return;
    }
};
