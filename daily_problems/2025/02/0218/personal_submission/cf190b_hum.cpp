#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if (dis > r1 + r2) {
    cout << setprecision(10) << (dis - r1 - r2) / 2 << endl;
  } else if (dis < abs(r1 - r2)) {
    cout << setprecision(10) << (abs(r1 - r2) - dis) / 2 << endl;
  } else {
    cout << 0 << endl;
  }
}
