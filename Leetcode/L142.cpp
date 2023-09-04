#include "../QuikTemplate.cpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        break;
    }
    if (fast != slow || fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    slow = head;
    ListNode *m = fast;
    while (slow != m) {
      slow = slow->next;
      m = m->next;
    }
    return slow;
  }
};