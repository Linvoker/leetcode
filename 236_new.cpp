#include<vector>
#include<iostream>
#include<queue>
#include<sstream>
#include<algorithm>
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
    //236.cpp有更快更优雅的写法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> l1; 
        buildAncestor(root, p, l1); //找到p的祖先路径
        vector<TreeNode*> l2; 
        buildAncestor(root, q, l2); //找到q的祖先路径
        
        //找到路径上最后一个相等的节点
        for (auto it1 = l1.rbegin(), it2 = l2.rbegin(); it1 != l1.rend() && it2 != l2.rend(); it1++, it2++) {
            if (*it1 != *it2) {
                return *(it1-1);
            } 
        }
        return l1.size() < l2.size() ? l1[0] : l2[0];
    }
    bool buildAncestor(TreeNode* root, TreeNode* t, vector<TreeNode*> &list) { //每次回头push_back父节点的轨迹，236.cpp是一路记着轨迹直接记录
        if (root == t) {
            list.push_back(root);
            return true;
        }
        if (root == nullptr) {
            return false; //该侧走到底了，没有等于t的
        }
        
        if (buildAncestor(root->left, t, list) || buildAncestor(root->right, t, list)) {
            list.push_back(root);
            return true;
        }
        return false;
    }
    
};
int main() {
    TreeNode * n1 = new TreeNode(1);
    TreeNode * n2 = new TreeNode(2);
    n1->left = n2;
    
    TreeNode *res = (new Solution())->lowestCommonAncestor(n1, n2, n1);
    cout << res->val << endl;
}

