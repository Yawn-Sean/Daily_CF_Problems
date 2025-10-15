/*
  https://codeforces.com/problemset/problem/1041/C
  kaicheng
  2025-06-08
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
#define int long long

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  auto f = [](pair<int, int> aa, pair<int, int> bb) {
    return aa.first < bb.first;
  };
  sort(a.begin(), a.end(), f);
  int cnt = 0;
  int cnt1 = 0;
  vector<int> ans(n);
  vector<int> order(n, 0);
  for (int i = 0; i < n; i++) {
    if (i <= cnt || a[i].first - a[cnt].first <= d) {
      order[i] = cnt1++;
    } else {
      order[i] = order[cnt++];
    }
  }
  cout << cnt1 << '\n';
  for (int i = 0; i < n; i++) {
    ans[a[i].second] = order[i];
  }
  for (auto &x : ans) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
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