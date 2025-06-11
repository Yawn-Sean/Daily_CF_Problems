int main() {
  int n; long long d; cin >> n >> d;
  long long L = 0, R = 0;
  int ans = 0;
  for (auto e: getv(n)) {
    if (e) {
      R = min(R + e, d);
      if ((L += e) > d)
        return puts("-1"), 0;
    }
    else {
      L = max(L, 0ll);
      if (R < 0)
        R = d, ++ ans;
    }
  }
  printf("%d", ans);
  return 0;
}
