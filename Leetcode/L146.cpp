// 146. LRU 缓存机制
#include "../QuikTemplate.cpp"

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
  DLinkedNode *head; // 维护head tail 两个虚拟节点
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
    if (!cache.count(key))
      return -1;
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
        DLinkedNode *removed = removeTail();
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

  void addToHead(DLinkedNode *node) { //
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