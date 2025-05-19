/*
  https://codeforces.com/problemset/problem/1915/G
  kaicheng
  2025-05-19
  so hard!
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

const int S_MAX = 1005;
const int INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  vector<int> S(n);
  for (auto &s : S)
    cin >> s;

  vector<vector<int>> dist(n, vector<int>(S_MAX, INF));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;

  int start_s = S[0];
  dist[0][start_s] = 0;
  pq.emplace(0, 0, start_s);

  while (!pq.empty()) {
    auto [d, u, s] = pq.top();
    pq.pop();

    if (d > dist[u][s])
      continue;

    for (auto [v, w] : adj[u]) {
      int new_dist = dist[u][s] + s * w;
      if (new_dist < dist[v][s]) {
        dist[v][s] = new_dist;
        pq.emplace(new_dist, v, s);
      }
    }

    int new_s = min(s, S[u]);
    if (dist[u][new_s] > dist[u][s]) {
      dist[u][new_s] = dist[u][s];
      pq.emplace(dist[u][new_s], u, new_s);
    }
  }

  int ans = INF;
  for (int s = 0; s < S_MAX; s++) {
    ans = min(ans, dist[n - 1][s]);
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}