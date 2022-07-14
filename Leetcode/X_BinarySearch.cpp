
#include <algorithm>
#include <cmath>
#include <cstdlib>
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
// https://github.com/wisdompeak/LeetCode#binary-search

/**
Find K-th Element
215.Kth-Largest-Element-in-an-Array (M)
287.Find-the-Duplicate-Number (H-)
378.Kth-Smallest-Element-in-a-Sorted-Matrix (H-)
373.Find-K-Pairs-with-Smallest-Sums (H)
668.Kth-Smallest-Number-in-Multiplication-Table (H-)
719.Find-Kth-Smallest-Pair-Distance (H-)
1918.Kth-Smallest-Subarray-Sum (M+)
2040.Kth-Smallest-Product-of-Two-Sorted-Arrays (H-)
1439.Find-the-Kth-Smallest-Sum-of-a-Matrix-With-Sorted-Rows (H)
786.Kth-Smallest-Prime-Fraction (H-)
793.Preimage-Size-of-Factorial-Zeroes-Function (H-)
1201.Ugly-Number-III (H-)
1539.Kth-Missing-Positive-Number (H-)
*/


