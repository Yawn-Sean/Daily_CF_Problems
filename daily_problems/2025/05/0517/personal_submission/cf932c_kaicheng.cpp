/*
  https://codeforces.com/problemset/problem/932/C
  kaicheng
  2025-05-17
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

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> v(n);
  iota(v.begin(), v.end(), 1);

  int i = 0;
  while (i < n) {
    if ((n - i) % b == 0) {
      if (b > 1)
        rotate(v.begin() + i, v.begin() + i + 1, v.begin() + i + b);
      i += b;
    } else {
      if (i + a > n) {
        cout << -1;
        return;
      }
      if (a > 1)
        rotate(v.begin() + i, v.begin() + i + 1, v.begin() + i + a);
      i += a;
    }
  }

  for (auto &x : v)
    cout << x << " ";
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