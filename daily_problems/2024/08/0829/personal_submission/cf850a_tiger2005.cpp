int main() {
  int n; cin >> n;
  if (n > 35)
    return puts("0"), 0;
  vector<int> ans;
  auto v = getv<array<int, 5>>(n, 1);
  for (int i = 1; i <= n; i ++) {
    bool flg = true;
    for (int j = 1; j <= n; j ++) if (j != i)
      for (int k = 1; k <= n; k ++) if (k != j && k != i) {
        int prod = 0;
        for (int x = 0; x < 5; x ++)
          prod += (v[j][x] - v[i][x]) * (v[k][x] - v[i][x]);
        if (prod > 0)
          flg = false;
      }
    if (flg)
      ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  write(ans, "%d\n");
  return 0;
}
