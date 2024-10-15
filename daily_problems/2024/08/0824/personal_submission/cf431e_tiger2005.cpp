struct Info {
  int cnt;
  i64 mx;
  i64 sm;
  i64 fill;
  Info() {
    cnt = mx = sm = fill = 0;
  }
  Info(int c, i64 x) {
    cnt = c;
    mx = x;
    sm = x * c;
    fill = 0;
  }
  Info operator + (const Info& i) const {
    Info res;
    res.cnt = cnt + i.cnt;
    res.mx = max(mx, i.mx);
    res.sm = sm + i.sm;
    res.fill = res.mx * res.cnt - res.sm;
    return res;
  }
};

int main() {
  int n, q; cin >> n >> q;
  auto a = getv<i64>(n, 1);
  vector<i64> nums = a; nums[0] = -1;
  vector<tuple<int, i64, i64>> qs;
  {
    int a; i64 b, c;
    for (int i = 1; i <= q; i ++) {
      cin >> a >> b;
      if (a == 1)
        cin >> c, nums.emplace_back(c);
      qs.emplace_back(a, b, c);
    }
  }
  sort(nums); unique(nums);
  int m = nums.size() - 1;
  vector<int> mp(m + 1);
  for (int i = 1; i <= n; i ++)
    a[i] = lower_bound(ALL(nums), a[i]) - nums.begin(), ++ mp[a[i]];
  SegTree<Info> tr(m + 1);
  for (int i = 1; i <= m; i ++)
    tr.modify(i, {mp[i], nums[i]});

  for (auto [op, b, c]: qs) {
    if (op == 1) {
      tr.modify(a[b], {-- mp[a[b]], nums[a[b]]});
      a[b] = lower_bound(ALL(nums), c) - nums.begin();
      tr.modify(a[b], {++ mp[a[b]], c});
    }
    else {
      int l = 1, r = m + 1;
      while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (tr.query(1, mid).fill <= b)
          l = mid;
        else
          r = mid;
      }
      auto q = tr.query(1, l);
      printf("%.8f\n", q.mx + 1.0 * (b - q.fill) / q.cnt);
    }
  }
  return 0;
}
