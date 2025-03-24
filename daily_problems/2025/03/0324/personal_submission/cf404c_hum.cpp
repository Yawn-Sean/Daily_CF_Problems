#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector cnt(n, k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  ranges::sort(idx, [&](int i, int j) { return a[i] < a[j]; });
  if (a[idx[0]] != 0 || a[idx[1]] == 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<int>> cur(n);
  vector<array<int, 2>> res;
  cur[0].push_back(idx[0]);
  for (int i = 1; i < n; i++) {
    int u = idx[i];
    int d = a[u];
    if (cur[d - 1].empty()) {
      cout << -1 << endl;
      return 0;
    }
    int v = cur[d - 1].back();
    res.push_back({v + 1, u + 1});
    cnt[v]--;
    if (cnt[v] == 0) {
      cur[d - 1].pop_back();
    }
    cnt[u]--;
    if (cnt[u] > 0) {
      cur[d].push_back(u);
    }
  }
  cout << res.size() << endl;
  for (auto [u, v]: res) {
    cout << u << " " << v << endl;
  }
}
