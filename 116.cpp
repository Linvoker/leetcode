/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //dfs，用递归，前序遍历，想要完成连接，必须完成一下要求1.让该结点左孩子的next指向右孩子，
 //2.如果该结点的next不为nullptr，则该结点右孩子的next指向该结点的next的左孩子，3.让其左子树和右子树分别完成连接
 //但事实上不能用递归，因为递归的空间复杂度会是O(lgn)，会创建函数调用栈，不是常数空间
 
 //bfs,层序遍历，层序遍历也要用O(lgn)的queue空间，但是有next可以代替queue。
 //用到了三个指针，一个指针指向前一层并从左向右移动，一个指针指向当前层，一个指针在当前层上从左向右移动
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        TreeLinkNode *pre_level = root;
        TreeLinkNode *curr_level = root->left;
        TreeLinkNode *move = nullptr;
        while (curr_level) {
            move = curr_level;
            bool mark = true;//mark用来标志pre_level和move的位置动态关系
            while (pre_level) {
                if (mark) {
                    move->next = pre_level->right;
                    pre_level = pre_level->next;
                } else {
                    move->next = pre_level->left;
                }
                move = move->next;
                mark = !mark;
            }
            pre_level = curr_level;
            curr_level = curr_level->left;
        }
        return;
    }
};
 
/*class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        } else if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
//bfs,层序遍历，层序遍历也要用O(lgn)的queue空间，但是有next可以代替queue。
//只需用两个指针，一个指针指向每一层的最左端结点，另一个指针在各层上不停地p = p->next,
//和递归的想法完全不同
/*class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        TreeLinkNode *mostLeftNode = root;
        TreeLinkNode *p = nullptr;
        
        while (mostLeftNode->left) {
            p = mostLeftNode;
            while (p && p->left && p->right) {
                p->left->next = p->right;
                if (p->next) {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            mostLeftNode = mostLeftNode->left;
        }
        return;
        
    }
};
