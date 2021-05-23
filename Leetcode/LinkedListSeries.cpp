#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
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


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // // L2
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        int carry = 0;
        ListNode *dummyNode = new ListNode();
        ListNode *cur = dummyNode;
        while (p != nullptr || q != nullptr) {
            int sum = (p == nullptr ? 0 : p->val) + (q == nullptr ? 0 : q->val) + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
            if (p != nullptr) {
                p = p->next;
            }
            if (q != nullptr) {
                q = q->next;
            }
        }
        if (carry != 0) {
            cur->next = new ListNode(carry);
        }
        return dummyNode->next;
    }

    // 83
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    // 82
    ListNode *deleteDuplicates_(ListNode *head) {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next != nullptr && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }

    // L86
    ListNode *partition(ListNode *head, int x) {
        ListNode *large = new ListNode();
        ListNode *largeHead = large;
        ListNode *small = new ListNode();
        ListNode *smallHead = small;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }

    // L445
    ListNode *addTwoNumbersⅡ(ListNode *l1, ListNode *l2) {
        ListNode *a = reverseListNode(l1);
        ListNode *b = reverseListNode(l2);
        ListNode *ans = addTwoNumbers(a, b);
        return reverseListNode(ans);
    }

    ListNode *reverseListNode(ListNode *head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    // L725
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        ListNode *cur = root;
        int N = 0;
        while (cur != nullptr) {
            cur = cur->next;
            N++;
        }
        int width = N / k, rem = N % k;
        vector < ListNode * > ans(k);
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode *head = cur;
            for (int j = 0; j < (width + (i < rem ? 1 : 0) - 1); ++j) { // 是 i < rem ? 1:0 不是 j<rem哦
                if (cur != nullptr) cur = cur->next;
            }
            if (cur != nullptr) {
                ListNode *prev = cur;
                cur = cur->next;
                prev->next = nullptr;
            }
            ans[i] = head;
        }
        return ans;
    }
};