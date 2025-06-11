#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  int nc{m};
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    if (b[i] == 0) { nc--; }
  }

  int sum = accumulate(b.begin(), b.end(), 0);

  int j{}, cnt{};
  vector<int> c(m);
  int res{n + 1};
  for (int i = 0; i < n; ++i) {
    while (j < n && cnt != nc) {
      c[a[j]]++;
      if (c[a[j]] == b[a[j]]) {
        cnt++;
      }
      j++;
    }
    if (cnt == nc) {
      res = min(res, j - i - sum);
    }
    c[a[i]]--;
    if (c[a[i]] == b[a[i]] - 1) {
      cnt--;
    }
  }
  if (res == n + 1) {
    cout << -1 << '\n';
  } else {
    cout << res << '\n';
  }
}
