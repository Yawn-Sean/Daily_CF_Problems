/*
  https://codeforces.com/problemset/problem/208/C
  kaicheng
  2025-05-13
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> cnt1(n, -1), q1{n - 1}; // v to n-1;
  cnt1[n - 1] = 0;

  // v to n-1 bfs
  for (int i = 0; i < q1.size(); i++) {
    int u = q1[i];
    for (auto &v : adj[u]) {
      if (cnt1[v] == -1) {
        cnt1[v] = cnt1[u] + 1;
        q1.push_back(v);
      }
    }
  }

  vector<int> cnt2(n, -1), q2{0}; // v to 0
  cnt2[0] = 0;

  // v to 0 bfs
  for (int i = 0; i < q2.size(); i++) {
    int u = q2[i];
    for (auto &v : adj[u]) {
      if (cnt2[v] == -1) {
        cnt2[v] = cnt2[u] + 1;
        q2.push_back(v);
      }
    }
  }

  // from 0 to all v shortest path num
  vector<int> dp2(n, 0);
  dp2[0] = 1;
  for (auto u : q2) {
    for (auto v : adj[u]) {
      if (cnt2[v] != -1 && cnt2[u] == cnt2[v] + 1) {
        dp2[u] += dp2[v];
      }
    }
  }

  // from all v to n-1 shortest path num
  vector<int> dp1(n, 0);
  dp1[n - 1] = 1;
  for (auto u : q1) {
    for (auto v : adj[u]) {
      if (cnt1[v] != -1 && cnt1[u] == cnt1[v] + 1) {
        dp1[u] += dp1[v];
      }
    }
  }

  ld ans = 1.0;
  int sum = dp2[n - 1];             // all shortest path num
  for (int i = 1; i < n - 1; i++) { // 跳过 0， n-1
    if (cnt2[i] + cnt1[i] == cnt2[n - 1]) {
      ld cnt = 2.0 * dp1[i] * dp2[i] / sum; //
      ans = max(ans, cnt);
    }
  }

  cout << fixed << setprecision(12) << ans << '\n';
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