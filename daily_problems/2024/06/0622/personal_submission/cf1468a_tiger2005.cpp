int tr[2000010];
void clr(int x, int l, int r) {
  tr[x] = 0;
  if (l == r)
    return;
  int m = (l + r) >> 1;
  clr(x << 1, l, m);
  clr(x << 1 | 1, m + 1, r);
}

void mdf(int x, int l, int r, int k, int v) {
  if (l == r)
    return tr[x] = v, void();
  int m = (l + r) >> 1;
  if (k <= m)
    mdf(x << 1, l, m, k, v);
  else
    mdf(x << 1 | 1, m + 1, r, k, v);
  tr[x] = max(tr[x << 1], tr[x << 1 | 1]);
}

int que(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr)
    return tr[x];
  int m = (l + r) >> 1, res = 0;
  if (ll <= m)
    res = que(x << 1, l, m, ll, rr);
  if (rr > m)
    res = max(res, que(x << 1 | 1, m + 1, r, ll, rr));
  return res;
}

int main() {
  multiCase() {
    int n; cin >> n;
    auto a = getv(n);
    vector<int> prev(n), stk;
    for (int i = 0; i < n; i ++) {
      while (!stk.empty() && a[stk.back()] <= a[i])
        stk.pop_back();
      prev[i] = (stk.empty()) ? -1 : stk.back();
      stk.push_back(i);
    }
    clr(1, 0, n - 1);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i ++)
      vp.emplace_back(a[i], i);
    for (auto [val, idx]: sorted(vp)) {
      int tmp = 0;
      if (idx != 0)
        tmp = max(tmp, que(1, 0, n - 1, prev[idx] + 1, idx - 1));
      if (prev[idx] != -1)
        tmp = max(tmp, que(1, 0, n - 1, 0, prev[idx]) + 1);
      mdf(1, 0, n - 1, idx, tmp + 1);
    }
    printf("%d\n", tr[1]);
  }
  return 0;
}
