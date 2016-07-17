/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //通过修改值来实现，但也非常难，因为是链表而非数组
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        for (ListNode *mark = head->next; mark != nullptr; mark = mark->next) {
            int val = mark->val;
            ListNode *run = head;
            while (run != mark && run->val <= val) {//找到前面已排序结点里大于ｖａｌ的最小值
                run = run->next;
            }
            if (run != mark) {
                ListNode *temp =run;//保留数字
                
                int x; //用两个变量来向右移动链表的值（只能这么做）
                int y = run->val;
                while (run != mark) {
                    x = y;
                    y = run->next->val;
                    run->next->val = x;
                    
                    run = run->next;
                } 
                temp->val = val;
            } 
        }
        return head;
        
    }
};
/*class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        for (ListNode *mark = head->next; mark != nullptr; mark = mark_next) {
            int val = mark->val;
            ListNode *run = head;
            ListNode *mark_next = mark->next;
            while (run->next != mark && run->next->val <= val) {//找到前面已排序结点里大于ｖａｌ的最小值
                run = run->next;
            }
            if (run->next != mark) {
                mark->next = run->next;
                run->next = mark;
                
                temp->val = val;
            } 
        }
        return head;
        
    }
};*/
/*class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sortedHead = new ListNode(-1);
        while(head != NULL)
        {
            //保存head位置
            ListNode *temp = head->next;
            ListNode *cur = sortedHead;
            while(cur->next != NULL && cur->next->val < head->val)
            {
                cur = cur->next;
            }
            //插入
            head->next = cur->next;
            cur->next = head;
            //恢复head
            head = temp;
        }
        return sortedHead->next;
    }
};*/
