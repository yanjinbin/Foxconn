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

// tag: 设计题 双端队列 double-end queue  deque
//  参考花花酱 https://zxi.mytechroad.com/blog/data-structure/leetcode-641-design-circular-deque/
// +1 -1 不要搞错 以及初始化的时候 head 设置成1 是因为insert front的时候 -1 为0  tail 同理
class MyCircularDeque {
private:
  const int k_;
  int head_;
  int tail_;
  int size_;
  vector<int> q_;

public:
  MyCircularDeque(int k) : k_(k), q_(k), head_(1), tail_(-1), size_(0) {}

  bool insertFront(int value) {
    if (isFull())
      return false;
    else {
      head_ = (head_ + k_ - 1) % k_;
      q_[head_] = value;
      if (size_ == 0)
        tail_ = head_;
      size_++;
      return true;
    }
  }

  bool insertLast(int value) {
    if (isFull())
      return false;
    else {
      tail_ = (tail_ + k_ + 1) % k_;
      q_[tail_] = value;
      if (size_ == 0)
        head_ = tail_;
      size_++;
      return true;
    }
  }

  bool deleteFront() {
    if (isEmpty())
      return false;
    else {
      head_ = (head_ + k_ + 1) % k_;
      size_--;
      return true;
    }
  }

  bool deleteLast() {
    if (isEmpty())
      return false;
    else {
      tail_ = (tail_ + k_ - 1) % k_;
      size_--;
      return true;
    }
  }

  int getFront() {
    if (isEmpty())
      return -1;
    return q_[head_];
  }

  int getRear() {
    if (isEmpty())
      return -1;
    return q_[tail_];
  }

  bool isEmpty() { return size_ == 0; }

  bool isFull() { return size_ == k_; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */