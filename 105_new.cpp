#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>
//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

using namespace std;

class Solution {
public:
    //看105的解释
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, inorder.size() - 1, 0);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int pos) {
        if (start == end) {
            return inorder[start] == preorder[pos] ? new TreeNode(inorder[start]) : nullptr;
        }
        if (start > end) {
            return nullptr;
        }
        int i = start;
        while (i <= end) {
            if (inorder[i] == preorder[pos]) {
                break;
            }
            i++;
        }
        int count = i - start;
        auto curNode = new TreeNode(preorder[pos]);
        curNode->left = helper(preorder, inorder, start, i - 1, pos + 1);
        curNode->right = helper(preorder, inorder, i + 1, end, pos + count + 1);
        return curNode;
    }
};
int main () {
    vector<int> pre{
        3,9,20,15,7
    };
    vector<int> in{
        9,3,15,20,7 
    };
    (new Solution())->buildTree(pre, in);
}
