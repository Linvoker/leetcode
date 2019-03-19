#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
#include<climits>
using namespace std;
typedef struct Node {
    int key;
    int val;
    //time_t timestamp; //不用最近访问的时间戳 链表尾就是最近访问的元素
    Node *last;
    Node *next;
} Node;
typedef struct List {
    Node *head;
    Node *tail;
} List;
class LRUCache {
public:
    LRUCache(int capacity) {
        this->maxSize = capacity;

        this->list = new List();
        this->list->head = this->list->tail = nullptr;
    }

    int get(int key) {
        if (this->um.find(key) != this->um.end()) {
            //更新list的位置到尾部
            this->deleteNodeFromList(this->um[key]); //不真的释放内存
            this->pushBackToList(this->um[key]);
            return this->um[key]->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (this->um.find(key) != this->um.end()) {
            //更新值
            //更新timestamp
            //更新到尾部
            this->deleteNodeFromList(this->um[key]); //不真的释放内存
            this->pushBackToList(this->um[key]);
            this->um[key]->val = value;

            return;//已经存在不用更新值
        } else {
            //不存在
            if (this->um.size() >= this->maxSize) {
                //删除头结点、map
                this->pop();
            }
            //插入新节点到尾部
            Node *newNode = new Node();
            newNode->val = value;
            newNode->key = key;

            this->pushBackToList(newNode);
            this->um[key] = newNode;
        }
    }
    //更新节点最近访问时间并且将节点丢到链表尾
    void pushBackToList(Node *p) {
        //p->timestamp = time(0);
        if (this->list->tail) {
            this->list->tail->next = p;
            p->last = this->list->tail;
        }
        this->list->tail = p;
        if (!this->list->head) {
            this->list->head = p;
        }
    }
    /**
     * 从list中移除元素，但map里保留
     */
    void deleteNodeFromList(Node *p) {
        if (!p->last && !p->next) { //没前没后
            this->list->head = nullptr;
            this->list->tail = nullptr;
        } else if (!p->last) { //头结点(没前)
            this->list->head = p->next;
            p->next->last = nullptr;
        } else if (!p->next) { //尾结点(没后)
            this->list->tail = p->last;
            p->last->next = nullptr;
        } else { //有前也有后
            p->last->next = p->next;
            p->next->last = p->last;
        }
        p->last = nullptr;
        p->next = nullptr;
    }
    //删除链表头结点、map中的信息、释放节点内存
    void pop() {
        if (!this->list->head) {
            return;
        }
        auto p = this->list->head;
        this->deleteNodeFromList(p);
        this->um.erase(p->key);
        delete(p);//注释掉这行速度会快一点
    }
//private:
    List *list; //节点列表
    unordered_map<int, Node*> um; //key => 节点地址
    unsigned int maxSize;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main () {
    // auto shit = new LRUCache(2);
    // shit->put(1,1);
    // shit->put(2,2);
    // cout <<shit->get(1) << endl;
    // shit->put(4,4);
    // cout << shit->get(2) << endl;
    // cout <<shit->get(3) << endl;
    // cout << shit->get(4) << endl;

    // auto shit = new LRUCache(1);
    // shit->put(2,1);
    // cout << shit->get(2) << endl;

    // auto shit = new LRUCache(1);
    // shit->put(2,1);
    // cout << shit->get(2) << endl;
    // shit->put(3,2);
    // cout << shit->get(2) << endl;
    // cout << shit->get(3) << endl;
    auto shit = new LRUCache(10);
    //vector<string> pa = {"put","put","put","put","get","get"};
    //vector<vector<int>> x = {{2,1},{1,1},{2,3},{4,1},{1},{2}};
     vector<string> pa = {"put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
     vector<vector<int>> x = {{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    for (int i = 0; i < pa.size(); i++) {
        if (pa[i] == "put") {
            int key = x[i][0];
            int val = x[i][1];
            shit->put(key, val);
            cout << "set " << key << " " << val << endl;
        } else if (pa[i] == "get") {
            cout << "get " << x[i][0] << " "<< shit->get(x[i][0]) << endl;
        }
        auto move = shit->list->head;
        while (move != nullptr) {
            cout << "key:" << move->key << " val:" << move->val << endl;
            move = move->next;
        }
        cout << endl;
        move = shit->list->tail;
        while (move != nullptr) {
            cout << "key:" << move->key << " val:" << move->val << endl;
            move = move->last;
        }
        cout << endl;
    }
}
// ["LRUCache","put","get"]
// [[1],[2,1],[2]]
// ["LRUCache","put","get","put","get","get"]
// [[1],[2,1],[2],[3,2],[2],[3]]
