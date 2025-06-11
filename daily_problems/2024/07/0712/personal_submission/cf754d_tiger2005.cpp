int main() {
  int n, k; cin >> n >> k;
  auto v = getv<int, int>(n);
  int ans = 0, ansl = 0;
  multiset<int> mts;
  for (auto [l, r]: sorted(v)) {
    mts.insert(r);
    while (!mts.empty() && (mts.size() > k || *mts.begin() < l))
      mts.erase(mts.begin());
    int R = *mts.begin();
    if (mts.size() == k && ans < R - l + 1)
      ans = R - l + 1, ansl = l;
  }
  printf("%d\n", ans);
  if (ans == 0) {
    for (int i = 1; i <= k; i ++)
      printf("%d ", i);
    return 0;
  }
  vector<int> al;
  for (auto [idx, val]: index(v, 1)) {
    auto [l, r] = val;
    if (l <= ansl && ansl + ans - 1 <= r)
      al.push_back(idx);
  }
  al.resize(k);
  write(al, "%d ");
  return 0;
}
