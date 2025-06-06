#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int inf = 1e9;
  int n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;

  auto cal = [&](int x, int y) {
    if (x % a == 0 && y % b == 0) {
      int t1 = x / a, t2 = y / b;
      if (t1 % 2 == t2 % 2) {
        return max(t1, t2);
      }
    }
    return inf;
  };
  int res = inf;
  res = min(res, cal(i - 1, j - 1));
  res = min(res, cal(i - 1, m - j));
  res = min(res, cal(n - i, j - 1));
  res = min(res, cal(n - i, m - j));
  if (res == inf) {
    cout << "Poor Inna and pony!" << '\n';
  } else {
    if (res and (n <= a or m <= b))
      cout << "Poor Inna and pony!" << "\n";
    else cout << res << "\n";
  }
}
