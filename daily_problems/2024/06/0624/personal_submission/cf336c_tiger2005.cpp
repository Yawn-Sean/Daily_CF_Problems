int main() {
  int n; cin >> n;
  auto a = getv(n);
  for (int i = 29; i >= 0; i --) {
    int num = (1 << 30) - 1;
    vector<int> c;
    for (auto e: a)
      if ((e >> i) & 1)
        num &= e, c.push_back(e);
    if (num % (1 << i) == 0 && !c.empty()) {
      printf("%d\n", (int)c.size());
      write(c, "%d ");
      return 0;
    }
  }
  return 0;
}
