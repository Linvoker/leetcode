/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution
 //思路1（较复杂）：bfs,用三个指针，一个指针指向调整层的前一层的所有结点lastLevelptr，一个指针指向调整层的最左端（不水平移动）mostLeftNode，
 //一个指针指向调整层的lastLevelptr的最右边孩子结点(会水平移动)mostRightNode
 //如果不用三个指针只用两个那么会出现很多嵌套循环，代码不直观
 
 //思路2（awesome！）：bfs，创建一个dummy结点，两个指针：一个指针指向当前要修改next成员的level（可向右移动），一个指针指向前一层（可向右移动）

//1.我的逻辑有点混乱，但是成功了
/*class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        TreeLinkNode *pre_level = root;
        TreeLinkNode *curr_level = root->left ? root->left : root->right;
        TreeLinkNode *move = curr_level;
        
        while (curr_level) {
            if (pre_level->left == curr_level && pre_level->right) {
                move->next = pre_level->right;
                move = move->next;
            }
            pre_level = pre_level->next;
            while (move && pre_level) {
                if (pre_level->left) {
                    move->next = pre_level->left;
                    move = move->next;
                    if (pre_level->right) {
                        move->next = pre_level->right;
                        move = move->next;
                    } 
                } else if (pre_level->right) {
                    move->next = pre_level->right;
                    move = move->next;
                } 
                pre_level = pre_level->next;
                
            }
            while (curr_level) {//更新curr_level和pre_level
                if (curr_level->left) {
                    pre_level = curr_level;
                    move = curr_level = curr_level->left;
                    break;
                } else if (curr_level->right) {
                    pre_level = curr_level;
                    move = curr_level = curr_level->right;
                    break;
                } else {
                    curr_level = curr_level->next;
                }
            }
        }
        
    }
};*/
//2.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy_node(INT_MIN);
        TreeLinkNode *cur_lev(&dummy_node);//可右移
        TreeLinkNode *pre_lev(root);//可右移
        
        while (1) {//停止条件在最底下
            while (pre_lev) {
                if (pre_lev->left) {
                    cur_lev->next = pre_lev->left;
                    cur_lev = cur_lev->next;
                }
                if (pre_lev->right) {
                    cur_lev->next = pre_lev->right;
                    cur_lev = cur_lev->next;
                }
                pre_lev = pre_lev->next;
            }
            pre_lev = dummy_node.next;
            
            if (cur_lev == &dummy_node) {//cur_lev指针没移动说明树底最后一层已经走完了了
                break;
            }
            cur_lev = &dummy_node;
        }
        return ;
    }

};
