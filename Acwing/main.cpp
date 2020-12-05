#include <iostream>
#include <queue>
#include <set>
#include <map>

#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main() {// https://tinyurl.com/y64wz26k https://tinyurl.com/y5wqw65e
    // lambda表达式
    int a = 123;
    auto fFunc = [&] {// 值捕获
        cout << a << endl;
    };
    a = 321;
    fFunc();
    //
    auto gFunc = [&a] {
        a = 899;
        cout << a << endl;
    };
    a = 999;
    gFunc();
    int b = 888;
    auto hFunc = [&] {
        cout << a << endl;
        cout << b << endl;
    };
    hFunc();

    auto kFunc = [=] {
        cout << a << "\t" << b << endl;
    };
    kFunc();
    // [capture list] (params list) mutable exception-> return type { function body }
    vector<int> arr = {1, 2, 3, 4, 5, -1};
    sort(arr.begin(), arr.end(), [](int a, int b) -> bool { return a < b; });
    FOR(i, 0, arr.size()) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    auto cmp = [](int a, int b) -> bool {
        return a > b;
    };
    set<int, decltype(cmp)> s(cmp);
    s.insert(10);
    s.insert(1);
    s.insert(11);
    s.insert(5);
    for (auto &c:s) {
        cout << c << " ";
    }
    cout << endl;
    map<int, int, decltype(cmp)> m(cmp);
    m[3] = 1;
    m[1] = 2;
    m[10] = 3;
    m[5] = 4;
    for (auto const &item:m) {
        cout << item.first << " | " << item.second << endl;
    }
    cout << endl;
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(5);
    q.push(2);
    q.push(10);
    cout << q.top() << endl;
    function<int(int, int)> Add = [](int a, int b) -> int {
        return a + b;
    };
    int ans = Add(1, 3);
    cout << ans << endl;
    function<void(int, int)> print_ = [](int a, int b) {
        cout << a + b << endl;
    };
    print_(999, 1);

    vector<string> names(5, "hello");
    FOR(i, 0, names.size()) {
        cout << names[i] << " ";
    }
    cout << endl;
    vector<vector<int>> grid(5, vector<int>(5, 1));
    FOR(i, 0, grid.size()) {
        FOR(j, 0, grid[i].size()) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
    }
    grid.resize(10);
    cout << grid.size() << endl;

    cout << endl;
    FOR(i, 0, grid.size()) {
        FOR(j, 0, grid[i].size()) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "here" << endl;
}
