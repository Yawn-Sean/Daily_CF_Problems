int main() {
  int n; cin >> n;
  auto a = getv<i64>(n);
  for (auto [x, y]: vector<pair<int, int>>{{0, 1}, {1, 2}, {0, 2}}) {
    i64 k = (a[y] - a[x]) * 2 / (y - x);
    set<int> st;
    for (auto [i, e]: index(a))
      st.insert(2 * e - i * k);
    if (st.size() == 2)
      return puts("Yes"), 0;
  }
  puts("No");
  return 0;
}
