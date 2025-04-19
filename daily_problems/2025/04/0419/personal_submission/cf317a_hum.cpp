#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y, m;
  cin >> x >> y >> m;
  if (x > y) {
    swap(x, y);
  }

  if (y >= m) {
    cout << 0 << endl;
    return 0;
  }
  if (y <= 0) {
    cout << -1 << endl;
    return 0;
  }
  long long res{};
  if (x < 0) {
    res += -x / y;
    x += -x / y * y;
  }
  while (max(x, y) < m) {
    if (x <= y)
      x += y;
    else
      y += x;
    res++;
  }
  cout << res << endl;
}
