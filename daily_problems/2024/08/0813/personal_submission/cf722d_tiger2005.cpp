int main() {
  int n; cin >> n;
  auto v = getv(n);
  int l = -1, r = 1e9 + 10;

  auto gen = [&] (int m) {
    vector<int> vec;
    set<int> st;
    for (auto e: v) {
      while (e > m || st.count(e))
        e /= 2;
      if (e == 0)
        continue;
      st.insert(e);
      vec.push_back(e);
    }
    return vec;
  };

  while (l < r - 1) {
    int m = (l + r) >> 1;
    set<int> vec;
    if (v.size() == gen(m).size())
      r = m;
    else
      l = m;
  }
  write(gen(r), "%d ", "\n");
  return 0;
}
