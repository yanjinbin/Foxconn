#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define pii pair<int, int>
using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    vector<int> cnt(26, 0);
    int len = s.length();
    int maxR = 0;
    for (int i = 0; i < len; i++) {
      int key = s[i] - 'a';
      cnt[key]++;
      maxR = max(cnt[key], maxR);
    }
    if (maxR > (len + 1) / 2)
      return "";
    priority_queue<pii> maxHeap;
    for (int i = 0; i < cnt.size(); i++) {
      if (cnt[i] > 0)
        maxHeap.push({cnt[i], i});
    }
    char lastContent = ' ';
    string ans;

    while (maxHeap.size() > 1) {
        pii m1 = maxHeap.top();
      maxHeap.pop();
      pii m2 = maxHeap.top();
      maxHeap.pop();
      char c1 = (char)(m1.second + 'a'), c2 = (char)(m2.second + 'a');
      if (c1 == lastContent) {
        ans += c2;
        ans += c1;
      } else {
        ans += c1;
        ans += c2;
        lastContent = c2;
      }
      m1.first--;
      m2.first--;
      if (m1.first > 0)
        maxHeap.push(m1);
      if (m2.first > 0)
        maxHeap.push(m2);
    }
    if (maxHeap.size() > 0) { // size = 1
      ans += maxHeap.top().second + 'a';
    }
    return ans;
  }
};

int main() {
  Solution INSTANCE;
  string ans = INSTANCE.reorganizeString("aaaabcd");
  cout << ans << endl;
  cout << "ok" << endl;
  string ret;
  // ret = ret +('a'+1)
  ret += ('a' + 1);
  ret += "c";
  ret += 'd';
  char c1 = 1 + 'a';
  char c2 = 2 + 'a';
  ret = ret + c1 + c2; // 不能写成 ret +=c1+c2;

  cout << ret << endl;
  cout << "===ok====" << endl;
  string s = "yyyy"; // 不能协程 string s = "yyyy"+c1;
  s = s + c1;
  cout << s << endl;

  return 0;
}