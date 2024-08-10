  multiCase() {
    int n, m; cin >> n >> m;
    auto a = getv(n);
    auto b = getv(m);
    vector<int> prv(n + 1), nxt(n + 1);
    for (int i = 1; i < n; i ++)
      nxt[a[i - 1]] = a[i], prv[a[i]] = a[i - 1];
    Z ans = 1;
    vector<bool> app(n + 1);
    for (auto e: b)
      app[e] = true;
    app[0] = true;
    for (auto e: b) {
      int ch = 0, count = 0;
      for (auto v: {prv[e], nxt[e]})
        if (!app[v])
          ch = v, ++ count;
      ans *= count;
      if (ch) {
        if (nxt[ch])
          prv[nxt[ch]] = prv[ch];
        if (prv[ch])
          nxt[prv[ch]] = nxt[ch];
      }
      app[e] = false;
    }
    printf("%d\n", (int)ans);
  }
  return 0;
}
