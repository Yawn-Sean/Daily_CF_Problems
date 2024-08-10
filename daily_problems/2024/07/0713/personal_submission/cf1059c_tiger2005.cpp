int main() {
  int n; cin >> n;
  auto dfs = [&] (auto self, int n, int coef) -> void {
    if (n <= 3) {
      for (int i = 1; i <= n; i ++)
        printf("%d ", (i == n ? i : 1) * coef);
      return;
    }
    for (int i = 1; i <= n; i += 2)
      printf("%d ", coef);
    self(self, n / 2, coef * 2);
  };
  dfs(dfs, n, 1);
  return 0;
}
