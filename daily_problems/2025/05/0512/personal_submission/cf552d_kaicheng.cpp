/*
  https://codeforces.com/problemset/problem/552/D
  kaicheng
  2025-05-12
*/

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first;
    cin >> x.second;
  }
  int ans = n * (n - 1) * (n - 2) / 6;

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if ((a[j].second - a[i].second) * (a[k].first - a[i].first) ==
            (a[k].second - a[i].second) * (a[j].first - a[i].first))
          ans--;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}