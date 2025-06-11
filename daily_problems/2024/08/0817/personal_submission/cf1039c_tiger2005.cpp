int fa[500010];
int getf(int x) {
  return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  auto v = getv<i64>(n, 1);
  Z ans = Z(2).pow(k + n), base = Z(2).pow(n), inv2 = Z(2).inv();
  map<i64, vector<pair<int, int>>> mp;
  for (auto [a, b]: getv<int, int>(m))
    mp[v[a] ^ v[b]].emplace_back(a, b);
  for (int i = 1; i <= n; i ++)
    fa[i] = i;
  for (auto &[_, v]: mp) {
    ans -= base;
    Z cur = base;
    for (auto &[a, b]: v)
      if (getf(a) != getf(b))
        fa[fa[a]] = fa[b], cur *= inv2;
    ans += cur;
    for (auto &[a, b]: v)
      fa[a] = a, fa[b] = b;
  }
  printf("%d", (int)ans);
  return 0;
}
