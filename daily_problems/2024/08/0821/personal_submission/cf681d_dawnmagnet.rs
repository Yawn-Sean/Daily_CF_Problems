int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);
    vector<bool> isroot(n, 1);

    while (m--) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      path[u].emplace_back(v);
      isroot[v] = 0;
    }

    vector<int> to_get(n);
    vector<bool> used(n, 0);
    for (auto &x : to_get)
      cin >> x, x--, used[x] = 1;

    vector<int> ans(n, -1), order, stk;
    for (int i = 0; i < n; i++)
      if (isroot[i])
        stk.push_back(i);

    while (!stk.empty()) {
      int u = stk.back();
      stk.pop_back();
      if (used[u]) {
        order.emplace_back(u);
        ans[u] = u;
      }
      for (auto &v : path[u]) {
        ans[v] = ans[u];
        stk.emplace_back(v);
      }
    }

    if (ans != to_get)
      cout << -1;
    else {
      reverse(order.begin(), order.end());
      cout << order.size() << '\n';
      for (auto &x : order)
        cout << x + 1 << '\n';
    }

    return 0;
  }