#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  int d1 = 0, d2 = 0;
  for (int j = 1; j <= m; j++) {
    d1 += (a[1][j] - a[n][j]) * (a[1][j] - a[n][j]);
    d2 += (a[n / 2][j] - a[n / 2 + 1][j]) * (a[n / 2][j] - a[n / 2 + 1][j]);
  }

  if (d2 < d1) {
    NO;
  } else {
    YES;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}