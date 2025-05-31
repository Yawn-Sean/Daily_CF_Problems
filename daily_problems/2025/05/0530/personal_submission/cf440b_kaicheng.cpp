/*
  https://codeforces.com/problemset/problem/440/B
  kaicheng
  2025-05-30
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  int avg = sum / n;
  int ans = 0, cnt = 0;
  for (auto &x : a) {
    cnt += x - avg;
    ans += abs(cnt);
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