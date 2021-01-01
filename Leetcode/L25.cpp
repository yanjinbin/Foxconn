#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vector <int> vi;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v){
        this->val=v;
        this->next= nullptr;
    }
};
class Solution{
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur  = head;
        int cnt =0;
        while (cnt <k){
            if(cur== nullptr)return head;
            cur = cur->next;
            cnt++;
        }
        ListNode* pre = reverseKGroup(cur,k);// 想想递归前后应该干嘛
        while (cnt > 0){
            ListNode* nxt =head->next;
            head->next=pre;
            pre =head;
            head =nxt;
            cnt--;
        }
        return pre;
    }
};
int main() { return 0; }