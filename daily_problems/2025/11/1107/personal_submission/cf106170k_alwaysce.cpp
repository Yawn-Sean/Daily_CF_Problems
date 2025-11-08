#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Edge {
  int u, v;
  i64 w;
};

/*
A <= sum(a[L:R]) + sum(delta) <= B
A - sum(a[L:R]) <= S[R] - S[L-1] <= B - sum(a[L:R])

S的差分约束 (s[x]-S[y] <= c) 可以转化为有向边 (y -> x) 权重 c
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> L(m), R(m);
  vector<i64> A(m), B(m);
  for (int j = 0; j < m; ++j) {
    cin >> L[j] >> R[j] >> A[j] >> B[j];
  }

  vector<i64> pref(n + 1, 0);
  for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];

  auto check = [&](long long k) -> bool {
    const int V = n + 1;
    vector<Edge> edges;

    for (int i = 1; i <= n; ++i) {
      i64 li = max(1LL - a[i - 1], -k);
      i64 ui = k;
      edges.push_back({i - 1, i, ui});
      edges.push_back({i, i - 1, -li});
    }

    for (int j = 0; j < m; ++j) {
      int l = L[j], r = R[j];
      i64 sumA = pref[r] - pref[l - 1];
      i64 Lsum = A[j] - sumA;
      i64 Usum = B[j] - sumA;
      edges.push_back({l - 1, r, Usum});
      edges.push_back({r, l - 1, -Lsum});
    }

    vector<i64> dist(V, 0);
    for (int it = 0; it < V; ++it) {
      bool any = false;
      for (auto& e : edges) {
        if (dist[e.v] > dist[e.u] + e.w) {
          dist[e.v] = dist[e.u] + e.w;
          any = true;
          if (it == V - 1) return false;
        }
      }
      if (!any) break;
    }
    return true;
  };

  i64 lo = 0, hi = 1e12;
  if (!check(hi)) {
    cout << -1 << '\n';
    return 0;
  }
  while (lo < hi) {
    i64 mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << '\n';
  return 0;
}
