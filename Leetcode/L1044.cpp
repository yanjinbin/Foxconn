#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> no{943, 1363, 1203, 834, 862, 1655, 1012, 233, 80, 940, 1095, 1462, 337, 124,
                   1136, 1349, 473, 1125, 638, 464, 691, 1632};
    sort(no.begin(), no.end());
    cout << no.size() << endl;
    for (int i = 0; i < no.size(); i++) {
        cout << no[i] << " ";
    }
    return 0;
}