int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (auto [a, b]: getv<int, int>(m)) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  set<int> unreached, temp;
  for (int i = 1; i <= n; i ++)
    unreached.insert(i);
  vector<vector<int>> ansl;
  while (!unreached.empty()) {
    int s = *unreached.begin();
    unreached.erase(s);

    vector<int> stk, cur;
    stk.push_back(s);
    while (!stk.empty()) {
      int x = stk.back();
      stk.pop_back();
      cur.push_back(x);
      for (auto e: g[x]) {
        auto ptr = unreached.find(e);
        if (ptr != unreached.end())
          unreached.erase(ptr), temp.insert(e);
      }
      swap(temp, unreached);
      for (auto &e: temp)
        stk.push_back(e);
      temp.clear();
    }

    ansl.push_back(cur);
  }
  printf("%d\n", (int)ansl.size());
  for (auto &e: ansl) {
    printf("%d", (int)e.size());
    write(e, " %d", "\n");
  }
  return 0;
}
