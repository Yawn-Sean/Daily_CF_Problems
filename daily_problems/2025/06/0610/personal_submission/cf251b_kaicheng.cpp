/*
  https://codeforces.com/problemset/problem/251/B
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
  int n;
  int k;
  cin >> n >> k;

  vector<int> q(n), s(n);
  for (auto &x : q)
    cin >> x;
  for (auto &x : s)
    cin >> x;

  vector<int> p(n);
  iota(p.begin(), p.end(), 1);

  if (p == s) {
    cout << (k == 0 ? "YES" : "NO") << '\n';
    return;
  }
  if (k == 0) {
    cout << "NO" << '\n';
    return;
  }

  vector<int> inv_q(n);
  for (int i = 0; i < n; ++i) {
    inv_q[q[i] - 1] = i + 1;
  }

  auto f = [&](vector<int> &cur, vector<int> &op) {
    int n = cur.size();
    vector<int> next(n);
    for (int i = 0; i < n; ++i) {
      next[i] = cur[op[i] - 1];
    }
    return next;
  };

  int s1 = 0;
  vector<int> p1 = p;
  for (int i = 1; i <= k; ++i) {
    p1 = f(p1, q);
    if (p1 == s) {
      s1 = i;
      break;
    }
    if (p1 == p)
      break;
  }

  int s2 = 0;
  vector<int> p2 = p;
  for (int i = 1; i <= k; ++i) {
    p2 = f(p2, inv_q);
    if (p2 == s) {
      s2 = i;
      break;
    }
    if (p2 == p)
      break;
  }

  bool flg1 = (s1 > 0 && k >= s1 && (k - s1) % 2 == 0);
  bool flg2 = (s2 > 0 && k >= s2 && (k - s2) % 2 == 0);

  if (q == inv_q) {
    if (s1 == k) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  } else {
    if (flg1 || flg2) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
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