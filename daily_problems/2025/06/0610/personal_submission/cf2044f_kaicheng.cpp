/*
  https://codeforces.com/problemset/problem/2044/F
  kaicheng
  2025-06-10
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
#define int long long

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n), b(m);
  int sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum_a += a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    sum_b += b[i];
  }
  set<int> st_a, st_b;
  for (int i = 0; i < n; i++) {
    st_a.insert(sum_a - a[i]);
  }
  for (int i = 0; i < m; i++) {
    st_b.insert(sum_b - b[i]);
  }

  auto check = [&](int x) {
    if (x == 0) {
      return st_a.count(0) || st_b.count(0);
    }
    bool neg = x < 0;
    x = abs(x);
    for (int i = 1; i * i <= x; i++) {
      if (x % i)
        continue;
      int j = x / i;
      if (neg) {
        if (st_a.count(i) && st_b.count(-j))
          return true;
        if (st_a.count(-i) && st_b.count(j))
          return true;
        if (st_b.count(i) && st_a.count(-j))
          return true;
        if (st_b.count(-i) && st_a.count(j))
          return true;
      } else {
        if (st_a.count(i) && st_b.count(j))
          return true;
        if (st_a.count(-i) && st_b.count(-j))
          return true;
        if (st_b.count(i) && st_a.count(j))
          return true;
        if (st_b.count(-i) && st_a.count(-j))
          return true;
      }
    }
    return false;
  };
  while (q--) {
    int x;
    cin >> x;
    cout << (check(x) ? "YES" : "NO") << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}