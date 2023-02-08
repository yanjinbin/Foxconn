#include "../QuikTemplate.cpp"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int v) {
    this->val = v;
    this->next = nullptr;
  }
};
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *cur = head;
    int cnt = 0;
    while (cnt < k) {
      if (cur == nullptr)
        return head;
      cur = cur->next;
      cnt++;
    }
    ListNode *pre = reverseKGroup(cur, k); // 想想递归前后应该干嘛
    while (cnt > 0) {
      ListNode *nxt = head->next;
      head->next = pre;
      pre = head;
      head = nxt;
      cnt--;
    }
    return pre;
  }
};
int main() { return 0; }