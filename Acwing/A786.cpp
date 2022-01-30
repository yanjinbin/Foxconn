#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F,
          kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pos = partition02(nums, left, right);
      if (pos == k - 1) return nums[pos];
      if (pos < k - 1) {
        left = pos + 1;
      } else {
        right = pos - 1;
      }
    }
  }

  int partition02(vector<int> &nums, int l, int r) {
    int pivotIdx = l;
    int index = l + 1;
    // 从左至右遍历
    for (int i = index; i <= r; i++) {
      if (nums[i] < nums[pivotIdx]) {
        swap(nums, i, index);
        index++;
      }
    }
    swap(nums, pivotIdx, index - 1);
    return index - 1;
  }

  // 交换数组值
  void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

// https://www.acwing.com/problem/content/788/ 786. 第k个数
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N, 0);
  FOR(i, 0, N) {
    cin >> arr[i];
  }
  Solution INSTANCE;
  int ans = INSTANCE.findKthLargest(arr, K);
  cout << ans << endl;
}
