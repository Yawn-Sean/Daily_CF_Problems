#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, x1, y1, z1, res = 0;
  cin >> x >> y >> z >> x1 >> y1 >> z1;
  vector<int> a(6);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  if (y < 0) res += a[0];
  if (y > y1) res += a[1];
  if (z < 0) res += a[2];
  if (z > z1) res += a[3];
  if (x < 0) res += a[4];
  if (x > x1) res += a[5];
  cout << res << endl;
}
