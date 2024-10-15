int main() {
  int n; cin >> n;
  auto a = getv(n);

  vector<i64> sm(5010);
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < i; j ++)
      ++ sm[abs(a[i] - a[j])];

  vector<i64> sm2(5010);
  for (int i = 0; i <= 5000; i ++)
    for (int j = 1; j < i; j ++)
      sm2[i] += sm[j] * sm[i - j];

  i64 ans = 0, cur = 0;
  for (int i = 1; i <= 5000; i ++) {
    ans += cur * sm[i];
    cur += sm2[i];
  }

  printf("%.12f\n", ans / pow(1.0 * n * (n - 1) / 2, 3));

  return 0;
}
