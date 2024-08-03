int perm[5] = { 0, 0, 1, 2, 9 };

int main() {
  int n, k; cin >> n >> k;
  Binom_bf<i64> bf;
  i64 ans = 1;
  for (int i = 0; i <= k; i ++)
    ans += bf.get(n, i) * perm[i];
  printf("%lld", ans);
  return 0;
}
