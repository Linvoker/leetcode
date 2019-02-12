//https://leetcode.com/problems/add-two-numbers
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{Val: -1, Next: nil} //头结点无实际意义，只是为了返回第一个节点
    curNode := head;
    carry := 0 //进位
    for l1 != nil || l2 != nil || carry == 1 {
        left := 0
        if l1 != nil {
            left, l1 = l1.Val, l1.Next
        }
        right := 0
        if l2 != nil {
            right, l2 = l2.Val, l2.Next
        }
        
        curVal := left + right + carry
    
        carry = 0
        if (curVal - 10 >= 0) {
            curVal -= 10
            carry = 1
        }
        
        curNode.Next = &ListNode{Val: curVal, Next: nil}
        curNode = curNode.Next

    }
    return head.Next
}
