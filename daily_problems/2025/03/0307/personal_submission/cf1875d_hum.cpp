#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int m{};
  for (int i = 0; i <= n; ++i) {
    if (!cnt.contains(i)) {
      m = i;
      break;
    }
  }
  int inf = 1e9;
  vector memo(m + 1, inf);

  function<int(int)> dfs = [&](int x) {
    if (x == 0) {
      return 0;
    }
    if (memo[x] != inf) {
      return memo[x];
    }
    int &res = memo[x];
    for (int i = 0; i < x; ++i) {
      res = min(res, (cnt[i] - 1) * x + i + dfs(i));
    }
    return res;
  };

  cout << dfs(m) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
