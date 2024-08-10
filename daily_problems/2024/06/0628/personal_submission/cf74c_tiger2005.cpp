int main() {
  int n, m; cin >> n >> m;
  printf("%d", gcd(n - 1, m - 1) + 1);
  return 0;
}
