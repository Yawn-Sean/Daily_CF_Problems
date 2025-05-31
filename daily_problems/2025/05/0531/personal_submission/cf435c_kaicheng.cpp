/*
  https://codeforces.com/problemset/problem/435/C
  kaicheng
  2025-05-31
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
#define PII pair<int, int>

const int N = 2005;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  vector<vector<char>> ans(N, vector<char>(N, ' '));
  int x = 1000, y = 0;
  int min_x = x, max_x = x;

  for (int i = 0; i < n; ++i) {
    char c = (i % 2) ? '\\' : '/';
    int dir = (i % 2) ? -1 : 1;

    ans[x][y] = c;
    for (int j = 1; j < a[i]; ++j) {
      y++;
      x += dir;
      ans[x][y] = c;
      min_x = min(min_x, x);
      max_x = max(max_x, x);
    }
    y++;
  }

  for (int i = max_x; i >= min_x; --i) {
    for (int j = 0; j < y; ++j) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
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