#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
#include<climits>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Node *res = new Node(head->val, nullptr, nullptr);
        Node *res = new Node;
        unordered_map<Node *, Node *> um;
        dfs(&(res->next), head, um);
        return res->next;
    }
    //想复杂了，dst可以作为返回值赋值，不用指针的指针
    void dfs(Node **dst, Node *src, unordered_map<Node *, Node *> &um) {
        if (src == nullptr) {
            *dst = nullptr;
            return;
        }
        if (um.find(src) != um.end()) {
            *dst = um[src];
            return;
        }

        *dst = new Node;
        (*dst)->val = src->val;
        um[src] = *dst;

        dfs(&((*dst)->next), src->next, um);

        dfs(&((*dst)->random), src->random, um);
    }
};
int main () {
    return 0;
}
