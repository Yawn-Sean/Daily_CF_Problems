#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

struct node {
  int id, p;
  bool operator<(const node &o) const { return p < o.p; }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i];

  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  if (n > 1) {
    for (int i = 0; i < n - 1; ++i) {
      int u, v, c;
      std::cin >> u >> v >> c;
      g[u].push_back({v, c});
      g[v].push_back({u, c});
    }
  }

  std::vector<int> fa(n + 1), cap(n + 1);
  if (n > 1) {
    std::vector<bool> vis(n + 1);
    std::vector<int> q;
    q.push_back(1);
    vis[1] = true;

    for (int i = 0; i < q.size(); ++i) {
      int u = q[i];
      for (auto [v, c] : g[u]) {
        if (!vis[v]) {
          vis[v] = true;
          fa[v] = u;
          cap[v] = c;
          q.push_back(v);
        }
      }
    }
  }

  std::vector<std::vector<node>> cur(n + 1), nxt(n + 1);
  if (n > 1) {
    for (int i = 2; i <= n; ++i)
      cur[i].push_back({i, a[i]});
  }

  std::vector<int> ans(n + 1);
  int cnt = 0, day = 0;
  int total = n > 1 ? n - 1 : 0;

  if (n > 1) {
    while (cnt < total) {
      for (int i = 1; i <= n; ++i) {
        for (auto [id, p] : nxt[i]) {
          if (i == 1) {
            if (!ans[id])
              ans[id] = day, cnt++;
          } else {
            cur[i].push_back({id, p});
          }
        }
        nxt[i].clear();
      }

      if (cnt == total)
        break;

      for (int i = 2; i <= n; ++i) {
        if (cur[i].empty())
          continue;
        std::sort(cur[i].begin(), cur[i].end());
        int sz = std::min((int)cur[i].size(), cap[i]);
        for (int j = 0; j < sz; ++j)
          nxt[fa[i]].push_back(cur[i][j]);
        cur[i].erase(cur[i].begin(), cur[i].begin() + sz);
      }
      day++;
    }
  }

  for (int i = 1; i <= n; ++i)
    std::cout << ans[i] << " \n"[i == n];

  return 0;
}