int main() {
  multiCase() {
    int d, m; cin >> d >> m;
    i64 ans = 1;
    for (int l = 1, r = 1; l <= d; l = r + 1) {
      r = min(2 * l - 1, d);
      ans = (ans * (r - l + 2)) % m;
    }
    printf("%lld\n", (ans + m - 1) % m);
  }
  return 0;
}
