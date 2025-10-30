#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MX = 1e6;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> path(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    --p;
    path[p].push_back(i);
    path[i].push_back(p);
  }

  vector<int> dep(n), fa(n, -1);
  vector<i64> subMax(n, LLONG_MIN);

  i64 ans = LLONG_MIN;
  int root = 0;
  vector<int> order;
  {
    vector<int> st = {root};
    fa[root] = -1;
    while (!st.empty()) {
      int u = st.back();
      st.pop_back();
      order.push_back(u);
      for (auto v : path[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        st.push_back(v);
      }
    }
  }

  for (int idx = n - 1; idx >= 0; --idx) {
    int u = order[idx];

    vector<pair<i64, int>> can;           // (subMax, child)
    can.emplace_back(a[u] + dep[u], -1);  // self

    for (auto& v : path[u]) {
      if (v == fa[u]) continue;
      can.emplace_back(subMax[v], v);
    }

    if (can.size() >= 2) {
      sort(can.rbegin(), can.rend());

      auto mx1 = can[0];
      i64 mx2_val = LLONG_MIN;
      for (int j = 1; j < (int)can.size(); j++) {
        if (can[j].second != mx1.second) {
          mx2_val = can[j].first;
          break;
        }
      }
      if (mx2_val != LLONG_MIN) {
        ans = max(ans, mx1.first + mx2_val - 2ll * dep[u]);
      }
    }

    subMax[u] = can[0].first;
  }
  cout << ans << "\n";

  return 0;
}
