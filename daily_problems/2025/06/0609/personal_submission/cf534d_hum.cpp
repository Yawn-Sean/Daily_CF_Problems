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
  vector<int> a(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g[a[i]].push_back(i + 1);
  }

  vector<int> res{};
  int cur{};
  while (res.size() < n) {
    if (!g[cur].empty()) {
      res.push_back(g[cur].back());
      g[cur].pop_back();
      cur++;
    } else {
      if (cur < 3) {
        cout << "Impossible";
        return 0;
      }
      cur -= 3;
    }
  }
  cout << "Possible" << '\n';
  for (auto x: res) cout << x << ' ';
}
