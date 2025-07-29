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
  vector<long long> vs(n), ds(n), ps(n);
  for (int i = 0; i < n; i++) {
    cin >> vs[i] >> ds[i] >> ps[i];
  }

  vector<bool> vis(n);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    res.push_back(i);
    long long v = vs[i];
    for (int j = i + 1; j < n; j++) {
      if (!vis[j] && v > 0) {
        ps[j] -= v;
        v--;
      }
    }
    long long cur{};
    for (int j = i + 1; j < n; j++) {
      ps[j] -= cur;
      if (!vis[j] && ps[j] < 0) {
        cur += ds[j];
        vis[j] = true;
      }
    }
  }
  cout << res.size() << '\n';
  for (auto i: res) {
    cout << i + 1 << ' ';
  }
}
