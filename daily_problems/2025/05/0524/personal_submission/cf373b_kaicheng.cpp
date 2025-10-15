/*
  https://codeforces.com/problemset/problem/373/B
  kaicheng
  2025-05-24
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

void solve() {
  int w, m, k;
  cin >> w >> m >> k;
  w /= k;

  auto f = [](int x) {
    int res = 0;
    int cnt = 1, d = 1;
    while (true) {
      if (cnt * 10 > x) {
        res += (x - cnt + 1) * d;
        break;
      }
      res += cnt * 9 * d;
      d++;
      cnt *= 10;
    }
    return res;
  };

  int l = m - 1, r = 2e16;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (f(mid) - f(m - 1) > w) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l - m << '\n';
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