#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> e(n);
  for (int i = 0; i < n; i++) {
    cin >> e[i];
  }
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    deg[v]++;
  }
  queue<int> q1, q2;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      if (e[i] == 0) {
        q1.push(i);
      } else {
        q2.push(i);
      }
    }
  }
  int res{};
  while (!q1.empty() || !q2.empty()) {
    while (!q1.empty()) {
      int u = q1.front();
      q1.pop();
      for (int v: g[u]) {
        deg[v]--;
        if (deg[v] == 0) {
          if (e[v] == 0) {
            q1.push(v);
          } else {
            q2.push(v);
          }
        }
      }
    }
    if (!q2.empty()) {
      res++;
    }
    while (!q2.empty()) {
      int u = q2.front();
      q2.pop();
      for (int v: g[u]) {
        deg[v]--;
        if (deg[v] == 0) {
          if (e[v] == 0) {
            q1.push(v);
          } else {
            q2.push(v);
          }
        }
      }
    }
  }
  cout << res << endl;
}
