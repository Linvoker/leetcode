/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //从head开始　与fast开始的循环一圈比较
 //有更高效的利用图形学的方法：http://blog.csdn.net/xy010902100449/article/details/48995255
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != nullptr && fast != slow) {
            slow = slow->next;
            if (fast->next != nullptr) { //这句很重要要，没有条件判断的话下一句会出现段错误
                fast = fast->next->next;
            } else {
                fast = fast->next;
            }
                
        }
        if (fast != slow) {
            return nullptr;
        } else { //有循环
            ListNode *find = fast;
            ListNode *mark = head;
            for (; ; mark = mark->next) { //时间复杂度为O(n^2),有一个O(n)的简单方法在那个博客里
            //    fast = fast->next;
                do{
                    fast = fast->next;
                } while (fast != mark && fast != find) ;
                
                if (fast == mark) {//这里不能用find判断，因为可能find == mark == fast的情况发生
                    return mark;
                }
            }
        }
        
        
    }
};
