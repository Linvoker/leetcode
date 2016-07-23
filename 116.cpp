/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //dfs，用递归，想要完成连接，必须完成一下要求1.让该结点左孩子的next指向右孩子，
 //2.如果该结点的next不为nullptr，则该结点右孩子的next指向该结点的next的左孩子，3.让其左子树和右子树分别完成连接
 //但事实上不能用递归，因为递归的空间复杂度会是O(lgn)，会创建函数调用栈，不是常数空间
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
};*/
//bfs,用两个指针，一个指针指向每一层的最左端结点，另一个指针在各层上不停地p = p->next,
//和递归的想法完全不同
class Solution {
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
