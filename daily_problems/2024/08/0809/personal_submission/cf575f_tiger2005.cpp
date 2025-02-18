int main() {
  int n, x; cin >> n >> x;
  int L = x, R = x;
  i64 ans = 0;
  for (auto [l, r]: getv<int, int>(n)) {
    if (R < l) {
      ans += l - R;
      tie(L, R) = tuple{R, l};
    }
    else if (r < L) {
      ans += L - r;
      tie(L, R) = tuple{r, L};
    }
    else {
      ckmax(L, l);
      ckmin(R, r);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
