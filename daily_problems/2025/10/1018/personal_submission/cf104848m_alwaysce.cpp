#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  /*
    (sum(l/v))(sum(cv)) >= (sum sqrt(lc))^2
  
    - sum(l/v) <= T
    
    sum(cv) >= (sum sqrt(lc))^2 / T
  */
  int n, m, T;
  cin >> n >> m >> T;
  vector<vector<pair<int, long double>>> path(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    long double l, c;
    cin >> u >> v >> l >> c;
    --u;
    --v;

    long double cost = sqrtl(l * c);
    path[u].emplace_back(v, cost);
    path[v].emplace_back(u, cost);
  }

  vector<long double> dist(n, 1e18);
  using PLI = pair<long double, int>;
  priority_queue<PLI, vector<PLI>, greater<PLI>> pq;

  dist[0] = 0.0;
  pq.emplace(0.0, 0);
  while (!pq.empty()) {
    auto [cd, u] = pq.top();
    pq.pop();
    if (cd > dist[u]) continue;
    for (auto [v, cost] : path[u]) {
      if (dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        pq.emplace(dist[v], v);
      }
    }
  }

  long double ans = dist[n - 1] * dist[n - 1] / ((long double)1.0 * (long double)T);
  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}
