#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// Rename to cf15b_alwaysCE.cpp
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;

  auto getArea = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
    return (x2 - x1 + 1) * (y2 - y1 + 1);
  };

  auto getIntersection = [&](i64 x1, i64 y1, i64 x2, i64 y2, i64 x3, i64 y3,
                             i64 x4, i64 y4) -> i64 {
    i64 left = max(x1, x3);
    i64 right = min(x2, x4);
    i64 top = max(y1, y3);
    i64 down = min(y2, y4);
    if (left > right || top > down) return 0;
    return getArea(left, top, right, down);
  };

  while (t--) {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;

    i64 left = min(x1 - 1, x2 - 1);
    i64 right = min(m - x1, m - x2);
    i64 top = min(n - y1, n - y2);
    i64 down = min(y1 - 1, y2 - 1);

    i64 tot1 = getArea(x1 - left, y1 - down, x1 + right, y1 + top);
    i64 tot2 = getArea(x2 - left, y2 - down, x2 + right, y2 + top);
    i64 tot3 = getIntersection(x1 - left, y1 - down, x1 + right, y1 + top,
                               x2 - left, y2 - down, x2 + right, y2 + top);
    cout << 1ll * n * m - (tot1 + tot2 - tot3) << endl;
  }
  return 0;
}
