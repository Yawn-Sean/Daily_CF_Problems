int main() {
  int n, q; cin >> n >> q;
  auto a = getv(n);

  bool special = !count(ALL(a), q);
  int las = 1;
  for (auto &e: a)
    las = (e == 0 ? (
      special ? special = false, e = q : e = las) : e);
  if (special)
    return puts("NO"), 0;

  vector<vector<int>> arr(q + 1);
  for (auto [idx, e]: index(a))
    arr[e].emplace_back(idx);
  vector<vector<int>> evts(n + 1);
  for (int i = 1; i <= q; i ++) if (arr[i].size())
    evts[arr[i].front()].push_back(i),
    evts[arr[i].back() + 1].push_back(- i);
  set<int> s;
  for (int i = 0; i < n; i ++) {
    for (auto e: evts[i])
      if (e > 0)
        s.insert(e);
      else
        s.erase(- e);
    if (a[i] != *s.rbegin())
      return puts("NO"), 0;
  }
  puts("YES");
  write(a, "%d ");
  return 0;
}
