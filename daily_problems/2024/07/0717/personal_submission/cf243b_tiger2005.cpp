int main() {
  auto [n, m, h, t] = read<int, 4>();
  vector<vector<int>> g(n + 1);
  for (auto [a, b]: getv<int, int>(m)) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int u = 1; u <= n; u ++) if ((int)g[u].size() > h)
    for (auto v: g[u]) if ((int)g[v].size() > t) {
      vector<bool> vb(n + 1), vc(n + 1);
      int cnt = 0;
      for (auto e: g[u]) if (e != v)
        cnt += !(vb[e] | vc[e]), vb[e] = true;
      for (auto e: g[v]) if (e != u)
        cnt += !(vb[e] | vc[e]), vc[e] = true;
      if (cnt >= t + h) {
        puts("YES");
        printf("%d %d\n", u, v);
        vector<int> v1, v2;
        for (int e = 1; e <= n; e ++) {
          if (vb[e] && !vc[e])
            v1.push_back(e);
          if (!vb[e] && vc[e])
            v2.push_back(e);
        }
        for (int e = 1; e <= n; e ++) if (vb[e] && vc[e])
          ((int)v1.size() >= h ? v2 : v1).push_back(e);
        v1.resize(h);
        v2.resize(t);
        write(v1, "%d ", "\n");
        write(v2, "%d ", "\n");
        return 0;
      }
    }
  puts("NO");
  return 0;
}
