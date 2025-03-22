#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector<array<int, 2>> ps;
  vector<long long> d1, d2;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ps.push_back({x, y});
    d1.push_back(1ll * (x - x1) * (x - x1) + 1ll * (y - y1) * (y - y1));
    d2.push_back(1ll * (x - x2) * (x - x2) + 1ll * (y - y2) * (y - y2));
  }
  long long res{ranges::max(d2)};
  for (int i = 0; i < n; ++i) {
    long long cur = d1[i];
    long long t = 0;
    for (int j = 0; j < n; ++j) {
      if (d1[j] > cur) {
        t = max(t, d2[j]);
      }
    }
    res = min(res, cur + t);
  }
  cout << res << endl;
}
