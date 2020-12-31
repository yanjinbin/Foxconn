#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  bool PossibleRBS(string s) {// is possible to obtain RBS !
    if ((s.size() % 2 == 1) || s.back() == '(' || s.front() == ')') {
      return false;
    } else {
      return true;
    }
  }
};
int main() {
  int T;
  cin >> T;
  Solution Instance;
  string s;
  while (T--) {
    cin >> s;
    cout << (Instance.PossibleRBS(s) ? "YES" : "NO") << endl;
  }

  return 0;
}