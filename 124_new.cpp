#include<vector>
#include<iostream>
//#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    //问题的关键在于找到状态转移方程
    //P(root) = max(P(root->left), P(root->right), 0) + root->val; //P(x) 是以x为根节点，向下的某一条路径的最大值
    //f(root) = max(root->val, root->val + P(root->left), root->val + P(root->right), root->val + P(root->left) + P(root->right)); //f(x)是以x为根节点的最大值
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        postorder(root, &maxVal);
        return maxVal;
    }
    //返回包含root并以root为根节点的某一条向下路径的最大值，curMax用来记录到达过的最大值
    int postorder(TreeNode *root, int *curMax) {
        if (root == nullptr) {return 0;}
        int left = postorder(root->left, curMax);
        int right = postorder(root->right, curMax);

        int res =  max(max(root->val + left, root->val + right), root->val);
        int nodeMax = max(max(root->val, root->val + left + right), res);
        *curMax = max(*curMax, nodeMax);
        return res;
    }
// [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
            // 9
        // 6       -3
    // null null -6     2
              // n  n  2  n 
                  // -6 -6 
                // -6
// -2
// 1 3
// [5,4,8,11,null,13,4,7,2,null,null,null,1]
            // 5
        // 4       8
    // 11  null 13    4
// 7    2   null null null 1
// 55, 48


    //别看这个，这是错的: 下面方法是后序遍历+自顶向下动态规划，使用了两个递归并且打表了，所以超过了空间复杂度
    //P(root) = max(P(root->left) + P(root->right) + root->val, max(P(root->left), P(root->right)));
    /* int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode *, int> table;
        int maxVal = INT_MIN;
        preorder(root, &maxVal, table);
        return maxVal;
    }
    void preorder(TreeNode *root, int *pmax, unordered_map<TreeNode *, int> &table) {
        if (root == nullptr) {return;}
        preorder(root->left, pmax, table);
        preorder(root->right, pmax, table);
        *pmax = max(dp(root, table), *pmax);
    }
    int dp(TreeNode *root, unordered_map<TreeNode *, int> &table) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        if (table.find(root) != table.end()) {
            return table[root];
        }
        return table[root] = max(max(root->val, max(root->val + dp(root->left, table), root->val + dp(root->right, table)));
    } */

};
int main() {
    TreeNode x(1);
    TreeNode y(-2);
    TreeNode z(3);
    y.left = &x;
    y.right = &z;
    cout << (new Solution())->maxPathSum(&y) << endl;
    return 0;
}
