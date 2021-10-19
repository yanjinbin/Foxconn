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

// tag: queue ring-buffer 循环队列
// go version answer : https://leetcode-cn.com/submissions/detail/226230409/
class MyCircularQueue {
private:
  vector<int> q_;
  int head_ = 0;
  int size_ = 0;

public:
  MyCircularQueue(int k) : q_(k) {}

  bool enQueue(int value) {
    if (isFull())
      return false;
    else {
      q_[(head_ + size_) % q_.size()] = value;
      ++size_;
      return true;
    }
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    else {
      head_ = (head_ + 1) % q_.size();
      --size_;
      return true;
    }
  }

  int Front() {
    if (isEmpty())
      return -1;
    return q_[head_];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    else
      return q_[(head_ + size_ - 1) % q_.size()];
  }

  bool isEmpty() { return size_ == 0; }

  bool isFull() { return size_ == q_.size(); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */