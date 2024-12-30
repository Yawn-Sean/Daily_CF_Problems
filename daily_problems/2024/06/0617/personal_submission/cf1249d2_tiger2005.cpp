int main() {
  int n, k; cin >> n >> k;
  auto a = sorted(index(getv<pair<int, int>>(n), 1), [&] (auto a, auto b) {
    return a.second < b.second;
  });
  set<pair<int, int>> st;
  vector<int> ans;
  for (auto [idx, val]: a) {
    auto [l, r] = val;
    while (!st.empty() && st.begin() -> first < l)
      st.erase(st.begin());
    st.insert({r, idx});
    if ((int)st.size() == k + 1) {
      auto ptr = prev(st.end());
      ans.push_back(ptr -> second);
      st.erase(ptr);
    }
  }
  printf("%d\n", (int)ans.size());
  write(ans, "%d ");
  return 0;
}
