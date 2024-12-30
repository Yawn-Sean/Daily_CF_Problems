int main() {
  int n; cin >> n;
  auto a = getv(n);
  set<pair<int, int>> st;
  set<tuple<int, int, int>> tp;

  auto merge = [&] (auto ptr) {
    if (ptr != tp.begin()) {
      auto tmp = prev(ptr);
      if (get<2>(*tmp) == get<2>(*ptr)) {
        auto [a, b, c] = *tmp;
        auto [d, e, f] = *ptr;
        tp.erase(tmp);
        tp.erase(ptr);
        ptr = tp.insert({a, b + e, c}).first;
        st.erase({- b, a});
        st.erase({- e, d});
        st.insert({- (b + e), a});
      }
    }
  };

  for (int i = 0; i < n; i ++) {
    st.insert({-1, i});
    merge(tp.insert({i, 1, a[i]}).first);
  }

  int ans = 0;
  while (!tp.empty()) {
    auto [mlen, mpos] = *st.begin();
    st.erase(st.begin());
    auto ptr = tp.lower_bound({mpos, 0, 0});
    ptr = tp.erase(ptr);
    if (ptr != tp.end())
      merge(ptr);
    ++ ans;
  }
  printf("%d", ans);
  return 0;
}
