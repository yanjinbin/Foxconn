#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>
using namespace std;

struct Point {
  int x, y, z;

  // operator > < 分表代表实现greater 和 less 比较器
  //  bool operator<(const Point &p) const { return this->x < p.x; }  // less
  bool operator>(const Point &p) const { return this->x > p.x; }  // greater
};

bool operator<(Point p1, Point p2) {
  return p1.x < p2.x;
}  // 重写struct内置的less和greater
bool cmpP(const Point &s1, const Point &s2) {
  return s1.x > s2.x;
}  // 自定义一个comparator函数

struct cmper {  // 自定义一个comparator struct
  bool operator()(const Point &p1, const Point &p2) { return p1.x < p2.x; }
};

struct Node {
  int x, y, z;
};

bool operator<(Node p1, Node p2) {
  return p1.x < p2.x;
}  // 默认的less比较器，可以放在struct之外

/*bool operator<(pii p1, pii p2) {
  return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first;
}*/
struct cmpPII {
  bool operator()(const pii &p1, const pii &p2) {
    return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first;
  }
};

// https://tinyurl.com/y6qyfa2s
int main() {
  cout << endl;
  vector<Point> vec;
  vec.push_back({1, 2, 3});
  vec.push_back({3, 4, 5});
  vec.push_back({6, 7, 8});
  sort(vec.begin(), vec.end());  // 默认采用struct对象内置的operator less比较器
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].x << " ";
  }
  cout << endl;
  sort(vec.begin(), vec.end(), cmper());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].x << " ";
  }
  cout << endl;
  sort(vec.begin(), vec.end(), cmpP);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].x << " ";
  }

  cout << endl;

  priority_queue<Node> q;  // 默认采用less比较器
  q.push({1, 3, 4});
  q.push({3, 4, 5});
  q.push({2, 1, 0});
  cout << q.top().x << endl;

  vector<pii> data;
  data.push_back({1, 2});
  data.push_back({3, 4});
  data.push_back({3, 5});
  data.push_back({3, 3});
  data.push_back({2, 1});
  sort(data.begin(), data.end());
  for (int i = 0; i < data.size(); i++) {
    cout << data[i].first << "-" << data[i].second << endl;
  }

  cout << "=====总结采用less比较器 bool operator<(Point p1, Point p2) { return"
          "p1.x < p2.x; } 比较方便====\n"
          "不需要注意添加const,\n "
          "声明为指针变量，适合各种容器vector和priority_queue"
       << endl;
  cout << "第二种选择 struct cmper {  // 自定义一个comparator struct\n"
          "  bool operator()(const Point &p1, const Point &p2) { return p1.x < "
          "p2.x; }\n"
          "}; 也适合vector和priority_queue"
       << endl;
  string line;
  return 0;
}