int tr[2000010];
void mdf(int x, int l, int r, int k, int v) {
  if (l == r)
    return tr[x] = v, void();
  int m = (l + r) >> 1;
  if (k <= m)
    mdf(x << 1, l, m, k, v);
  else
    mdf(x << 1 | 1, m + 1, r, k, v);
  tr[x] = min(tr[x << 1], tr[x << 1 | 1]);
}
int que(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr)
    return tr[x];
  int m = (l + r) >> 1, res = 1e9;
  if (ll <= m)
    res = que(x << 1, l, m, ll, rr);
  if (rr > m)
    res = min(res, que(x << 1 | 1, m + 1, r, ll, rr));
  return res;
}

int main() {
  int n, m; cin >> n >> m;
  auto a = getv(n, 1);
  vector<vector<pair<int, int>>> g(n + 1);
  vector<int> ans(m, -1);
  for (auto [idx, val]: index(getv<int, int>(m))) {
    auto [l, r] = val;
    g[l].emplace_back(r, idx);
  }
  map<int, int> las;
  vector<int> nxt(n + 1);
  for (int i = 1; i <= n; i ++) {
    if (!las[a[i]])
      mdf(1, 1, n, i, 1e9);
    else
      mdf(1, 1, n, i, i - las[a[i]]), nxt[las[a[i]]] = i;
    las[a[i]] = i;
  }
  for (int i = 1; i <= n; i ++) {
    for (auto [r, idx]: g[i]) {
      int tmp = que(1, 1, n, i, r);
      if (tmp != 1e9)
        ans[idx] = tmp;
    }
    if (nxt[i])
      mdf(1, 1, n, nxt[i], 1e9);
  }
  write(ans, "%d\n");
  return 0;
}
