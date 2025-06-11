int main() {
  auto [a, b, n] = reads<int, int, int>();
  int M = 1e6;
  vector<long long> pres(M + 1);
  for (int i = 1; i <= M; i ++)
    pres[i] = (a + 1ll * (i - 1) * b) + pres[i - 1];
  for (auto [l, t, m]: getv<int, int, int>(n)) {
    int lp = l - 1, rp = M + 1;
    while (lp < rp - 1) {
      int mid = (lp + rp) >> 1;
      if ((pres[mid] - pres[l - 1]) <= 1ll * t * m && a + 1ll * b * (mid - 1) <= t)
        lp = mid;
      else
        rp = mid;
    }
    if (lp == l - 1)
      puts("-1");
    else
      printf("%d\n", lp);
  }
  return 0;
}
