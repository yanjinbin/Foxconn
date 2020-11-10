#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int getNumberOfK(vector<int> &v, int k) {
    auto l = lower_bound(v.begin(), v.end(), k);
    auto r = upper_bound(v.begin(), v.end(), k);
    return r - l;
}

int main() {
    //
    vector<int> v = {1, 2, 3, 3, 3, 3, 4, 5};
    cout << getNumberOfK(v, 3) << endl;
}