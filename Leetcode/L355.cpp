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

// tag: 设计题 设计推特
constexpr size_t kMaxTweets = 10;

class Twitter {
private:
  int time;
  unordered_map<int, deque<pii>> user_tweets_;
  unordered_map<int, set<int>> followers;

public:
  Twitter() {}
  void postTweet(int userId, int tweetId) {
    auto &tweets = user_tweets_[userId];
    if (tweets.size() == kMaxTweets) {
      tweets.pop_front();
    }
    tweets.emplace_back(++time, tweetId);
  }

  vector<int> getNewsFeed(int userId) {
    vector<pii> feed(begin(user_tweets_[userId]), end(user_tweets_[userId]));
    for (int uid : followers[userId])
      feed.insert(end(feed), begin(user_tweets_[uid]), end(user_tweets_[uid]));
    sort(rbegin(feed), rend(feed));
    vector<int> ans;
    for (int i = 0; i < min(kMaxTweets, feed.size()); ++i)
      ans.push_back(feed[i].second);
    return ans;
  }

  void follow(int followerId, int followeeId) {
    if (followeeId == followerId)
      return;
    followers[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    followers[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */