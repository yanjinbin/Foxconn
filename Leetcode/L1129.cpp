#include "../QuikTemplate.cpp"

class Solution {
public:
  // https://youtu.be/ZobIimNrSFA
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
    vector<unordered_set<int>> edgeR(n), edgeB(n);
    for (auto &e : redEdges) {
      edgeR[e[0]].insert(e[1]);
    }
    for (auto &e : blueEdges) {
      edgeB[e[0]].insert(e[1]);
    }
    unordered_set<int> seenR, seenB;
    // init
    vector<int> ans(n, -1); // node color, color of last edge visit node, 0 red,1 blue.
    queue<pii> q;
    // dummy node
    q.push({0, 0});
    q.push({0, 1});
    seenR.insert(0), seenB.insert(0);
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int p = q.front().FI;
        int is_blue = q.front().SE;
        q.pop();
        ans[p] = ans[p] >= 0 ? min(ans[p], steps) : steps; // first or update
        auto &edges = is_blue ? edgeR : edgeB;
        auto &seen = is_blue ? seenR : seenB;
        for (int nxt : edges[p]) {
          if (seen.count(nxt))
            continue;
          seen.insert(nxt);
          q.push({nxt, 1 - is_blue}); // switch blue red
        }
      }
      steps++;
    }
    return ans;
  }
};