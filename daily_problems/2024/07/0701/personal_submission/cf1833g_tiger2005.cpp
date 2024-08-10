int main() {
  multiCase() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (auto [idx, val]: index(getv<int, int>(n - 1), 1)) {
      auto [a, b] = val;
      -- a, -- b;
      g[a].emplace_back(b, idx);
      g[b].emplace_back(a, idx);
    }
    vector<int> ans;
    auto dfs = [&] (auto self, int x, int f) -> int {
      int res = 1;
      for (auto [v, id]: g[x]) if (v != f) {
        int r = self(self, v, x);
        if (r == -1)
          return -1;
        if (r == 3)
          ans.emplace_back(id);
        else
          res += r;
      }
      return res > 3 ? -1 : res;
    };
    if (dfs(dfs, 0, 0) != 3)
      puts("-1");
    else {
      printf("%d\n", (int)ans.size());
      write(ans, "%d ");
      puts("");
    }
  }
  return 0;
}
