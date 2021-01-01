

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
// lcm 最小公倍数 （ Least Common Multiple）
int lcm(int a, int b) {
  return (a * b / gcd(a, b));
}
// 最小公倍数*最大公约数 = 两数之积
int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(27, 15) << endl;
}