#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<long long, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  vector<pair<long long, int>> dis;
  for (int i = 1; i < n; i++) {
    a[i][0] -= a[0][0];
    a[i][1] -= a[0][1];
    long long d = a[i][0] * a[i][0] + a[i][1] * a[i][1];
    dis.emplace_back(d, i);
  }
  ranges::sort(dis);

  int u = dis[0].second;
  for (int i = 1; i < n - 1; i++) {
    int v = dis[i].second;
    long long t = a[u][0] * a[v][1] - a[v][0] * a[u][1];
    if (t != 0) {
      cout << 1 << " " << u + 1 << " " << v + 1 << "\n";
      return 0;
    }
  }
}
