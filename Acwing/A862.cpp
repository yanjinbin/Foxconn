#include <vector>
#include <iostream>
#include <tuple>

#define debug puts("pigtoria bling bling ⚡️⚡️");
using namespace std;

int main() {
    auto comp = [](tuple<int, double, string> p, tuple<int, double, string> q) -> bool {
        int x1 = get<0>(p), x2 = get<0>(q);
        double y1 = get<1>(p), y2 = get<1>(q);
        string z1 = get<2>(p), z2 = get<2>(q);
        return x1 != x2 ? x1 < x2 : (y1 != y2 ? y1 < y2 : (z1 < z2));
    };
    vector<tuple<int, double, string>> tups;
    int N;
    int x;
    double y;
    string z;
    cin >> N;
    while (N--) {
        cin >> x >> y >> z;
        tups.push_back(tie(x, y, z));
    }
    sort(tups.begin(), tups.end(), comp);
    for (int i = 0; i < tups.size(); i++) {
        tuple<int, double, string> t = tups[i];
        printf("%d %.2lf %s\n", get<0>(t), get<1>(t), get<2>(t).c_str());
    }
}