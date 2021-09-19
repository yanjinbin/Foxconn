// 146. LRU 缓存机制
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second


struct DLinkedNode {
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0) {}

    DLinkedNode(int _key, int _value) {
        this->key = _key;
        this->value = _value;
    }
};
// GET PUT操作都是O(1)
class LRUCache {
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;// 维护head tail 两个虚拟节点
    DLinkedNode *tail;
    int size;
    int cap;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key))return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            size++;
            if (size > cap) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }


    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(DLinkedNode *target) {
        DLinkedNode *prev = target->prev;
        DLinkedNode *next = target->next;
        prev->next = next;
        next->prev = prev;
    }

    void addToHead(DLinkedNode *node) {//
        DLinkedNode *nxt = head->next;
        head->next = node;
        node->prev = head;
        nxt->prev = node;
        node->next = nxt;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */