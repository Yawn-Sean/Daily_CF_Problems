#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, s, t;
  cin >> n >> k >> s >> t;
  vector<array<int, 2>> a(n);
  int m{};
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    m = max(m, a[i][1]);
  }
  vector<int> g(k + 2);
  for (int i = 0; i < k; i++) {
    cin >> g[i];
  }
  g[k] = 0, g[k + 1] = s;
  ranges::sort(g);
  function<bool(int)> check = [&](long long v) {
    long long time{};
    for (int i = 0; i < k + 1; i++) {
      long long len = g[i + 1] - g[i];
      if (len > v) {
        return false;
      }
      long long x = min(v - len, len);
      time += 2 * len - x;
    }
    return time <= t;
  };

  int l{1}, r{m + 1};
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  int inf = 1e9 + 5;
  int res{inf};

  for (int i = 0; i < n; i++) {
    if (a[i][1] >= l) {
      res = min(res, a[i][0]);
    }
  }
  cout << (res == inf ? -1 : res) << '\n';
}
