#include<vector>
#include<iostream>
#include<algorithm>
//#include<unordered_set>
#include<climits>

using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;

        make_heap(this->nums.begin(), this->nums.end(), comp); //O(n)
        int i = k, size = this->nums.size();
        while (i++ < size) { //O(klogn) //建n堆之后pop掉 得到一个大小为k的最小堆
            pop_heap(this->nums.begin(), this->nums.end(), comp);
            this->nums.pop_back();
        }
        /*if (this->nums.size() > k) { //堆比k大//建一个大小为k的最小堆
            make_heap(this->nums.begin(), this->nums.begin() + k, comp);  //O(k)
            for (auto it = this->nums.begin() + k; it != this->nums.end(); it++) { //O(nlogk)
                if (*it > this->nums[0]) {
                    pop_heap(this->nums.begin(), this->nums.begin() + k, comp);
                    this->nums[k - 1] = *it;
                    push_heap(this->nums.begin(), this->nums.begin() + k, comp);
                }
            }
            this->nums.resize(k);
        } else { //k比堆大//建一整个最小堆
            make_heap(this->nums.begin(), this->nums.end(), comp);
        }*/
        this->k = k;
    }

    int add(int val) { //O(logk)
        if (this->nums.size() < k) {
            this->nums.push_back(val); //若堆的大小小于k 直接放入
            push_heap(this->nums.begin(), this->nums.end(), comp); //heapify
        } else if (val > this->nums[0]) {
            pop_heap(this->nums.begin(), this->nums.end(), comp); //先把小顶堆的顶移除(到尾部)再做heapify
            this->nums[this->nums.size() - 1] = val;  //最小值替换成当前值
            push_heap(this->nums.begin(), this->nums.end(), comp); //heapify
        }

        return this->nums[0];
    }
private:
    vector<int> nums;
    int k;

    static bool comp(int x, int y) {
        return x > y;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main() {
    int k = 3;
    vector<int> nums = {4,5,8,2};
    KthLargest* obj = new KthLargest(k, nums);
    //["KthLargest","add","add","add","add","add"]
     //   length >= k - 1
//[[2,[0]],[-1],[1],[-2],[-4],[3]]
//["KthLargest","add","add","add","add","add"]
// [[3,[4,5,8,2]],[3],[5],[10],[9],[4]]

    // [null,3,4,5,8,8]
    // [null,4,5,5,8,8]
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout <<  obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    //int param_1 = obj->add(3);
}
