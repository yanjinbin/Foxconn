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
// tag: 设计题 tinyurl 编解码
class Solution {
private:
  unordered_map<string, string> short2long, long2short;
  string dict;

public:
  Solution() {
    dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    short2long.clear();
    long2short.clear();
    srand(time(NULL));
  }
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (long2short.count(longUrl))
      return "http://tinyurl.com/" + long2short[longUrl];
    string key = randStr();
    while (short2long.count(key)) {
      key = randStr();
    }
    long2short[longUrl] = key;
    short2long[key] = longUrl;
    return key;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) { return short2long[shortUrl]; }

  string randStr() {
    for (int i = 0; i < 6; i++)
      shortUrl += dict[rand() % 62];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));