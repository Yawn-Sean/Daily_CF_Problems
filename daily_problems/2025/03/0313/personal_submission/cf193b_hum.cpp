#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, u, r;
  cin >> n >> u >> r;
  vector<int> a(n), b(n), k(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  long long ans = -1e18;
  function<void(vector<int> &, int, int)> dfs = [&](vector<int> &cur, int step, int first) {
    if ((u - step) % 2 == 0) {
      long long res{};
      for (int i = 0; i < n; i++) {
        res += cur[i] * k[i];
      }
      ans = max(ans, res);
    }
    if (step == u) {
      return;
    }

    vector<int> ncur(n);
    for (int i = 0; i < n; i++) {
      ncur[i] = cur[p[i]] + r;
    }
    dfs(ncur, step + 1, 0);
    if (first == 0) {
      for (int i = 0; i < n; i++) {
        ncur[i] = cur[i] ^ b[i];
      }
      dfs(ncur, step + 1, 1);
    }
  };

  dfs(a, 0, 0);
  cout << ans << endl;
}
