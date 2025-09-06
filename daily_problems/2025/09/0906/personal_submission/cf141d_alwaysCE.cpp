#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Edge {
  int to;
  i64 cost;
  int ramp_no;
};

struct Ramp {
  int depart, arrive;
  int id;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, L;
  cin >> n >> L;
  vector<int> xs(n), ds(n), ts(n), ps(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ds[i] >> ts[i] >> ps[i];
  }

  vector<i64> pts;
  pts.push_back(0);
  pts.push_back(L);

  vector<Ramp> ramps;
  ramps.reserve(n);

  for (int i = 0; i < n; i++) {
    if (xs[i] - ps[i] < 0) continue;
    int depart = xs[i] - ps[i];
    int arrive = xs[i] + ds[i];
    pts.push_back(depart);
    pts.push_back(arrive);
    pts.push_back(xs[i]);

    ramps.push_back({depart, arrive, i + 1});
  }

  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  int m = pts.size();
  auto idx = [&](int x) {
    return int(lower_bound(pts.begin(), pts.end(), x) - pts.begin());
  };

  vector<vector<Edge>> adj(m);
  for (int i = 0; i + 1 < m; i++) {
    i64 w = pts[i + 1] - pts[i];
    adj[i].push_back({i + 1, w, -1});
    adj[i + 1].push_back({i, w, -1});
  }

  for (auto &[depart, arrive, id] : ramps) {
    int u = idx(depart);
    int v = idx(arrive);
    i64 w = ts[id - 1] + ps[id - 1];
    adj[u].push_back({v, w, id});
  }

  int st = idx(0);
  int ed = idx(L);

  i64 inf = 1e18;
  vector<i64> dist(m, inf);

  vector<int> pre(m, -1);
  vector<int> use_ramp(m, -1);

  priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
  dist[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto &edge : adj[u]) {
      int v = edge.to;
      i64 nd = d + edge.cost;
      if (nd < dist[v]) {
        dist[v] = nd;
        use_ramp[v] = edge.ramp_no;
        pre[v] = u;
        pq.push({nd, v});
      }
    }
  }

  cout << dist[ed] << "\n";
  vector<int> ans;
  for (int v = ed; v != st; v = pre[v]) {
    if (use_ramp[v] != -1) {
      ans.push_back(use_ramp[v]);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int ramp : ans) {
    cout << ramp << " ";
  }
  cout << "\n";
  return 0;
}
