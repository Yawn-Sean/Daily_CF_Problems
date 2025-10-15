#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> c;

void pri(int v) {
  c[v] = -c[v];
  cout << " " << v + 1;
}

int main() {
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  function<void(int, int)> dfs = [&](int u, int p) {
    for (auto v: g[u]) {
      if (v == p) {
        continue;
      }
      pri(v);
      dfs(v, u);
      pri(u);
      if (c[v] == -1) {
        pri(v);
        pri(u);
      }
    }

    if (u == 0 && c[u] == -1) {
      pri(g[u][0]);
      pri(u);
      pri(g[u][0]);
    }
  };
  cout << "1";
  dfs(0, -1);
}
