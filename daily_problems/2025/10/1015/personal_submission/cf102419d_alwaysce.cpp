#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> node(n);
  for (int i = 0; i < n; i++) {
    cin >> node[i];
  }

  vector<pair<int, int>> edges;
  vector<vector<int>> eq(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edges.emplace_back(u, v);
    if (node[u] == node[v]) {
      eq[u].push_back(v);
      eq[v].push_back(u);
    }
  }

  vector<int> color(n, -1);
  auto bfs = [&](int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : eq[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;
          q.push(v);
        } else if (color[v] == color[u]) {
          return false;
        }
      }
    }

    return true;
  };

  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      if (!bfs(i)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (color[i] == 1) {
      ans.push_back(i + 1);
    }
  }

  vector<int> used((1 << 20) + 1);
  for (auto& [u, v] : edges) {
    if (color[u] != color[v]) {
      used[node[u] ^ node[v]] = 1;
    }
  }

  int x = 0;
  while (used[x]) {
    x++;
  }
  cout << ans.size() << " " << x << endl;
  if (ans.size() > 0) {
    for (auto& v : ans) {
      cout << v << " ";
    }
    cout << endl;
  }
  /*
    不相等的时候就 x不能取node[u]^node[v]
    相等的时候 二分图
  */
  return 0;
}
