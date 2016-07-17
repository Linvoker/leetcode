/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //借用以前写的reverseList()来完成
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *return_val = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return return_val;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode root(-1);
        root.next = head;
        
        ListNode *temp = &root;
        
        ListNode *m_node_pre;
        ListNode *n_node_pre;
        for (int j = 1; j != n + 1; j++, temp = temp->next) {
            if (j == m) {//找到第ｍ-1个结点
                m_node_pre = temp;
            } 
            if (j == n) {//找到第ｎ-1个结点
                n_node_pre = temp;
            }
        }
        
        ListNode *m_node = m_node_pre->next;//第ｍ个结点
        ListNode *n_node = n_node_pre->next;//第ｎ个结点
        
        ListNode *followed = n_node->next;//保存ｎ后面的结点
        n_node->next = nullptr;//将ｎ后面的结点暂时移除，以便翻转
        
        m_node_pre->next = reverseList(m_node);
        m_node->next = followed;//恢复ｎ后面的结点
        
       
        return root.next;
      
    }
};
