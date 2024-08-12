int main() {
  string s; cin >> s;
  vector<int> zero, one;
  for (auto [idx, e]: index(s, 1)) {
    if (e == '1') {
      if (zero.empty())
        return puts("-1"), 0;
      int u = zero.back();
      zero.pop_back();
      one.push_back(u);
      l[u].push_back(idx);
    }
    else {
      if (one.size()) {
        int u = one.back();
        one.pop_back();
        zero.push_back(u);
        l[u].push_back(idx);
      }
      else {
        l[++ cnt].push_back(idx);
        zero.push_back(cnt);
      }
    }
  }
  if (one.size())
    return puts("-1"), 0;
  printf("%d\n", (int)zero.size());
  for (auto e: zero) {
    printf("%d", (int)l[e].size());
    write(l[e], " %d", "\n");
  }
  return 0;
}
