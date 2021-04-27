#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
const double PI=3.1415926;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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


class Solution_v1 {
private:
    double rad;
    double x0;
    double y0;
public:
    Solution_v1(double radius, double x_center, double y_center) {
        this->rad = radius;
        this->x0 = x_center;
        this->y0 = y_center;
    }

    vector<double> randPoint() {
        double p1 = (double) rand() / RAND_MAX;
        double p2 = (double) rand() / RAND_MAX;
        double x1 = 2 * p1 * rad - rad + x0;//2*p*radius-radius ∈ [-radius,+radius]
        double y1 = 2 * p2 * rad - rad + y0;
        bool ok = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) <= rad * rad;
        if (ok)return {x1, y1};
        else return randPoint();
    }
};

// tag:极坐标
class Solution_v2 {
private:
    double rad;
    double x0;
    double y0;
public:
    double PI = 3.1415926;
    Solution_v2(double radius, double x_center, double y_center) {
        rad = radius;
        x0 = x_center;
        y0 = y_center;
    }

    vector<double> randPoint() {
        double r = (double)rand()/RAND_MAX;
        r = sqrt(r)*rad;
        double  theta =  ((double)rand()/RAND_MAX) * 2 * PI ;
        double x =x0+r*sin(theta);
        double y =y0+r*cos(theta);
        return {x,y};
    }
};

