#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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

// tag: 设计题 单链表 https://zxi.mytechroad.com/blog/list/leetcode-707-design-linked-list/
// warn: 不要写错 corner case
class MyLinkedList {
public:
  MyLinkedList() : head_(nullptr), tail_(nullptr), dummy_(0), size_(0){};
  ~MyLinkedList() {
    Node *node = head_;
    while (node) {
      Node *cur = node;
      node = node->next;
      delete cur;
    }
    head_ = nullptr;
    tail_ = nullptr;
  }
  int get(int index) {
    if (index < 0 || index >= size_)
      return -1;
    else
      return getNode(index)->val;
  }
  // 错误
  //   void addAtHead(int val) {
  //     head_ = new Node(val, head_);
  //     if (size_ == 0)
  //       tail_ = head_;
  //     size_ = size_ + 1;
  //   }

  void addAtHead(int val) {
    head_ = new Node(val, head_);
    if (size_++ == 0)
      tail_ = head_;
  }
  // 错误
  //   void addAtTail(int val) {
  //     auto node = new Node(val);
  //     if (size_ == 0) {
  //       head_ = tail_ = node;
  //     }
  //     size_ = size_ + 1;
  //     tail_->next = node;
  //     tail_ = node;
  //   }

  void addAtTail(int val) {
    auto node = new Node(val);
    if (size_++ == 0) {
      head_ = tail_ = node;
    } else {
      tail_->next = node;
      tail_ = tail_->next;
    }
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size_) {
      return;
    }
    if (index == 0)
      return addAtHead(val);
    if (index == size_)
      return addAtTail(val);
    else {
      Node *prev = getNode(index - 1);
      prev->next = new Node(val, prev->next);
      size_ = size_ + 1;
      return;
    }
  }
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size_)
      return;
    Node *prev = getNode(index - 1);
    Node *node_to_delete = prev->next;
    prev->next = node_to_delete->next;
    if (index == 0)
      head_ = prev->next;
    if (index == size_ - 1)
      tail_ = prev;
    delete node_to_delete;
    --size_;
  }

private:
  struct Node {
    int val;
    Node *next;
    Node(int _val) : Node(_val, nullptr) {}
    Node(int _val, Node *_next) : val(_val), next(_next) {}
  };

  Node *head_; // Does not own
  Node *tail_; // Does not own
  Node dummy_;
  int size_;

  Node *getNode(int index) {
    dummy_.next = head_;
    Node *n = &dummy_;
    for (int i = 0; i <= index; ++i)
      n = n->next;
    return n;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */