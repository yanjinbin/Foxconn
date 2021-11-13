#include <algorithm>
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

// bit manipulation
class Solution {
public:
  // 89 格雷码 https://youtu.be/K3_IvifT0pI
  vector<int> grayCode_02(int n) {
    vector<int> rets = {0};
    if (n == 0)
      return rets;
    for (int i = 0; i < n; i++) {
      int len = rets.size();
      for (int j = len - 1; j >= 0; j--) {
        rets.PB(rets[j] | (1 << i));
      }
    }
    return rets;
  }

  // https://bit.ly/3n34tns
  vector<int> grayCode_01(int n) {
    int start = 0;
    int nn = 1 << n;
    vector<int> res(nn, 0);
    for (int i = 0; i < nn; ++i) {
      res[i] = i ^ (i >> 1) ^ start;
    }

    return res;
  }

  // L136
  int singleNumber(vector<int> &nums) {
    int ans = 0; // 取 0 是因为 0 ^ A = A // A ^ A = 0 , A ^ B ^ B = A
    for (int i = 0; i < nums.size(); i++) {
      ans = ans ^ nums[i];
    }
    return ans;
  }
  // L137
  int singleNumber(vector<int> &nums) {
    vector<int> bits(32, 0);
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      for (int j = 0; j < 32; j++) {
        bits[j] += ((x >> j) & 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      if (bits[i] % 3 != 0) {
        ans += (1 << i);
      }
    }
    return ans;
  }

  // L260 https://bit.ly/3mM7esX bit操作技巧  tag: classic
  vector<int> singleNumber(vector<int> &nums) {
    long s = 0;
    for (auto n : nums)
      s = s ^ n;
    long t = s ^ (s & (s - 1)); // only keep the rightmost set bit
    int a = 0, b = 0;
    for (auto n : nums) {
      if (n & t)
        a ^= n;
      else
        b ^= n;
    }
    return {a, b};
  }

  // L318
  int maxProduct(vector<string> &words) {
    vector<int> codes(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      string s = words[i];
      int code = 0;
      for (int j = 0; j < s.size(); j++) {
        code |= (1 << (s[j] - 'a'));
      }
      codes[i] = code;
    }
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if ((codes[i] & codes[j]) != 0)
          continue;
        ans = max(ans, (int)(words[i].size() * words[j].size()));
      }
    }
    return ans;
  }

  // 371
  int getSum(int a, int b) {
    while (b != 0) {
      unsigned int carry = (unsigned int)(a & b) << 1;
      a = a ^ b; // sum
      b = carry; // carry
    }
    return a;
  }

  // L957  https://youtu.be/Pt_GU2eOo5Q
  vector<int> prisonAfterNDays(vector<int> &cells, int n) {
    unordered_map<int, int> state;
    int x = 0;
    for (int i = 0; i < cells.size(); i++) {
      x += cells[i] << i;
    }
    int tick = 0;
    int k = x;
    while (state.find(k) == state.end()) {
      state[k] = tick;
      // update
      k = (~((k >> 1) ^ (k << 1))) & (0b01111110);
      tick++;
    }
    int cycle = tick - state[k];

    int s = state[k];
    if (n >= cycle) {
      n = (n - s) % cycle + s;
    }
    // reset
    k = x;
    for (int i = 0; i < n; i++) {
      k = (~((k >> 1) ^ (k << 1))) & (0b01111110);
    }

    vector<int> ans(8);
    for (int i = 0; i < 8; i++) {
      ans[i] = (k >> i) & 1;
    }
    return ans;
  }

  // L1310
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> preX(n + 1, 0);
    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
      ret = ret ^ arr[i];
      preX[i + 1] = ret;
    }
    vector<int> ans;
    for (auto range : queries) {
      int l = range[0] + 1;
      int r = range[1] + 1;
      ans.push_back(preX[r] ^ preX[l - 1]);
    }
    return ans;
  }

  // L1442
  int countTriplets(vector<int> &arr) {
    unordered_map<int, vector<int>> map;
    map[0].push_back(-1); // 解释初始化原因 https://youtu.be/DwvNIVLcT8U?t=913
    int ans = 0, xorsum = 0;
    for (int k = 0; k < arr.size(); k++) {
      xorsum ^= arr[k];
      for (auto i : map[xorsum]) {
        ans += k - i - 1; // k-(i+2)+1
      }
      map[xorsum].push_back(k);
    }
    return ans;
  }
  // L1506 plus题目跳过
  // L1734
  vector<int> decode(vector<int> &encoded) {
    int n = encode.size() + 1;
    int xorsum = 0;
    for (int i = 1; i <= n; i++) {
      xorsum = xorsum ^ i
    }
    int nohead = 0;
    for (int i = 1; i < encoded.size(); i = i + 2) {
      nohead = nohead ^ encoded[i];
    }
    int head = xorsum ^ nohead;
    vector<int> ans(n);
    ans[0] = head;
    for (int i = 1; i < n; i++) {
      ans[i] = encoded[i - 1] ^ ans[i - 1];
    }
    return ans;
  }

  // L1738
  int kthLargestValue(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        arr[i + 1][j + 1] = arr[i + 1][j] ^ arr[i][j + 1] ^ arr[i][j] ^ matrix[i][j];
      }
    }
    // top-k 问题
    int left = 0, right = INT_MAX;
    while (left < right) {
      int mid = right - (right - left) / 2;
      if (countGreater(arr, mid) < k)
        right = mid - 1;
      else
        left = mid;
    }
    return left;
  }

  int countGreater(vector<vector<int>> pre, int v) {
    int count = 0;
    for (int i = 1; i < pre.size(); i++)
      for (int j = 1; j < pre[0].size(); j++)
        if (pre[i][j] >= v)
          count++;
    return count;
  }

  // 1835  https://youtu.be/W0tTPpOgTxM
  int getXORSum(vector<int> &arr1, vector<int> &arr2) {
    vector<int> ones(32);
    for (auto x : arr2)
      for (int i = 0; i < 32; i++)
        if (((x >> i) & 1) == 1)
          ones[i]++;

    int ret = 0;
    for (auto x : arr1) {
      int ans = 0;
      for (int i = 0; i < 32; i++)
        if (((x >> i) & 1 == 1) && (ones[i] % 2 == 1))
          ans += (1 << i);
      ret ^= ans;
    }
    return ret;
  }

  // =============================================分割线=============================================
  // tag: bit-mask

  // L1239
  int maxLength(vector<string> &arr) {
    vector<int> a;
    for (const string &x : arr) {
      int mask = 0;
      for (char c : x) {
        mask |= 1 << (c - 'a'); // 不是1 >> (c-'a');哦
      }
      if (__builtin_popcount(mask) != x.length())
        continue; //有重复元素
      a.push_back(mask);
    }
    int ans = 0;
    function<void(int, int)> dfs = [&](int s, int mask) {
      ans = max(ans, __builtin_popcount(mask));
      for (int i = s; i < a.size(); i++) {
        if ((mask & a[i]) == 0)
          dfs(i + 1, mask | a[i]);
      }
    };
    dfs(0, 0);
    return ans;
  }

  // L1601
  int maximumRequests(int n, vector<vector<int>> &requests) {
    int m = requests.size();
    int ans = 0;
    /* for (int state = 0; state < (1 << m); state++) {
       int count = 0;
       if (check(state, n, requests)) {
         ans = max(ans, cnt(state));
       }
     }
     return ans;*/
    // Gosper's Hack 优化
    /*
    // Iterate all the m-bit state where there are k 1-bits.

    int state = (1 << k) - 1;
    while (state < (1 << m))
    {
      doSomething(state);

      int c = state & - state;
      int r = state + c;
      state = (((r ^ state) >> 2) / c) | r;
    }*/
    for (int k = m; k >= 0; k--) {
      int state = (1 << k) - 1;
      while (state < (1 << m)) {
        if (check(state, n, requests))
          return k;
        int c = state & -state;
        int r = state + c;
        state = (((r ^ state) >> 2) / c) | r;
      }
    }
    return 0;
  }

  bool check(int s, int n, vector<vector<int>> &requests) {
    int m = requests.size();
    vector<int> net(n, 0);
    for (int i = 0; i < m; i++) {
      if (((s >> i) & 1) == 1) {
        net[requests[i][0]]--;
        net[requests[i][1]]++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (net[i] != 0) {
        return false;
      }
    }
    return true;
  }

  int cnt(int state) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      if ((state >> i) & 1 == 1)
        cnt++;
    }
    return cnt;
  }

  // L1755
  int minAbsDifference(vector<int> &nums, int goal) {
    const int n = nums.size();
    int ans = abs(goal);
    vector<int> t1{0}, t2{0}; //不选也是一种选择!
    t1.reserve(1 << (n / 2 + 1));
    t2.reserve(1 << (n / 2 + 1));
    // https://youtu.be/h0CpI4N813Q?t=1871
    for (int i = 0; i < n / 2; ++i)
      for (int j = t1.size() - 1; j >= 0; --j) //必须从大到小!
        t1.push_back(t1[j] + nums[i]);
    for (int i = n / 2; i < n; ++i)
      for (int j = t2.size() - 1; j >= 0; --j)
        t2.push_back(t2[j] + nums[i]);
    sort(t2.begin(), t2.end());
    for (int x : unordered_set<int>(begin(t1), end(t1))) {
      auto it = lower_bound(t2.begin(), t2.end(), goal - x);
      if (it != t2.end())
        ans = min(ans, abs(goal - x - *it));
      if (it != t2.begin())
        ans = min(ans, abs(goal - x - *prev(it)));
    }
    return ans;
  }

  // L2035 类似 1755
  // L1755
  int minAbsDifference(vector<int> &nums, int goal) {
    const int n = nums.size();
    int ans = abs(goal);
    vector<int> t1{0}, t2{0}; //不选也是一种选择!
    t1.reserve(1 << (n / 2 + 1));
    t2.reserve(1 << (n / 2 + 1));
    // https://youtu.be/h0CpI4N813Q?t=1871
    for (int i = 0; i < n / 2; ++i)
      for (int j = t1.size() - 1; j >= 0; --j) //必须从大到小!
        t1.push_back(t1[j] + nums[i]);
    for (int i = n / 2; i < n; ++i)
      for (int j = t2.size() - 1; j >= 0; --j)
        t2.push_back(t2[j] + nums[i]);
    sort(t2.begin(), t2.end());
    for (int x : unordered_set<int>(begin(t1), end(t1))) {
      auto it = lower_bound(t2.begin(), t2.end(), goal - x);
      if (it != t2.end())
        ans = min(ans, abs(goal - x - *it));
      if (it != t2.begin())
        ans = min(ans, abs(goal - x - *prev(it)));
    }
    return ans;
  }

  // L2035 类似 1755 https://youtu.be/pl49uriKwjk?t=1810
  int minimumDifference(vector<int> &nums) {
    int n = nums.size() / 2;
    vector<int> nums1(nums.begin(), nums.begin() + n);
    vector<int> nums2(nums.begin() + n, nums.begin() + 2 * n);

    auto help = [&](vector<int> arr) -> unordered_map<int, vector<LL>> {
      unordered_map<int, vector<LL>> map;
      int n = arr.size();
      for (int state = 0; state < (1 << n); state++) {
        int ones = __builtin_popcount(state);
        LL sum = 0;
        for (int k = 0; k < n; k++) {
          if (((state >> k) & 1) == 1) {
            sum += (LL)arr[k];
          }
        }
        map[ones].push_back(sum);
      }
      for (auto &x : map) {
        sort(x.second.begin(), x.second.end());
      }
      return map;
    };

    unordered_map<int, vector<LL>> dict = help(nums2); // key-> j  elements of nums, value is  sum of fixed nums j
    LL sum = accumulate(nums.begin(), nums.end(), 0LL);
    LL ans = LLONG_MAX;

    for (int state = 0; state < (1 << n); state++) {
      int ones = __builtin_popcount(state);
      LL x = 0;
      for (int k = 0; k < n; k++) {
        if (((state >> k) & 1) == 1) {
          x += (LL)nums1[k];
        }
      }
      int key = n - ones;
      auto it = lower_bound(dict[key].begin(), dict[key].end(), sum / 2 - x);
      if (it != dict[key].end()) {
        LL y = *it;
        ans = min(ans, abs(sum - 2 * x - 2 * y));
      }
      if (it != dict[key].begin()) {
        LL y = *prev(it);
        ans = min(ans, abs(sum - 2 * x - 2 * y));
      }
    }
    return ans;
  }

  unordered_map<int, vector<LL>> help(vector<int> &nums) {
    unordered_map<int, vector<LL>> map;
    int n = nums.size();
    for (int state = 0; state < (1 << n); state++) {
      int ones = __builtin_popcount(state);
      LL sum = 0;
      for (int k = 0; k < n; k++) {
        if (((state >> k) & 1) == 1) {
          sum += (LL)nums[k];
        }
      }
      map[ones].push_back(sum);
    }
    for (auto &x : map) {
      sort(x.second.begin(), x.second.end());
    }
    return map;
  }
};