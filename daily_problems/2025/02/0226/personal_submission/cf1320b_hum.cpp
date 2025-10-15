#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g1(n), g2(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g1[u].push_back(v);
    g2[v].push_back(u);
  }
  int t;
  cin >> t;
  vector<int> a(t);
  for (int i = 0; i < t; i++) {
    cin >> a[i];
    --a[i];
  }

  vector d(n, -1);

  queue<int> q;
  q.push(a.back());
  d[a.back()] = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int u = q.front();
      q.pop();
      for (int v: g2[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
  }

  int res1{0}, res2{0};

  for (int i = 0; i < t - 1; i++) {
    int u = a[i], v = a[i + 1];
    if (d[v] != d[u] - 1) {
      res1++;
      res2++;
    } else {
      for (int x: g1[u]) {
        if (x != v && d[x] == d[u] - 1) {
          res2++;
          break;
        }
      }
    }
  }
  cout << res1 << " " << res2 << "\n";
}
