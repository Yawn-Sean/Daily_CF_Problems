#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector b(n, 0);
  for (int i = 0; i < m; i++) {
    int p, s;
    cin >> p >> s;
    s--;
    b[s] = max(b[s], p);
  }
  for (int i = n - 2; i >= 0; --i) {
    b[i] = max(b[i], b[i + 1]);
  }
  int res = 0;
  for (int i = 0; i < n;) {
    int t = a[i];
    int j = 0;
    while (t <= b[j]) {
      j++;
      if (i + j >= n) {
        break;
      }
      t = max(t, a[i + j]);
    }
    if (j == 0) {
      cout << -1 << endl;
      return;
    }
    res++;
    i += j;
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
