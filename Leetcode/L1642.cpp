#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i < (b); i++)
using namespace std;

// binary search
int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    const int n = heights.size();
    if (ladders >= n - 1) return n - 1;
    vector<int> diffs(n);
    for (int i = 1; i < n; ++i)
        diffs[i - 1] = max(0, heights[i] - heights[i - 1]);
    int l = ladders;
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        vector<int> d(begin(diffs), begin(diffs) + m);
        nth_element(begin(d), end(d) - ladders, end(d));
        if (accumulate(begin(d), end(d) - ladders, 0) > bricks)
            r = m;
        else
            l = m + 1;
    }
    return l - 1;
}

// https://youtu.be/FowBaF5hYcY
int main() {

//    priority_queue<int> q;
//    q.push(9);q.push(8);
//    q.push(2);
//    int val = q.top();
//    cout << val <<endl;



    /*vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10;
    int ladders = 2;
    int ans = furthestBuilding(heights, bricks, ladders);
    cout << "结果\t" << ans << endl;*/
    return 0;
}


