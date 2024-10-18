int main() {
  int n, m; cin >> n >> m;
  auto a = getv(n, 1);
  vector<int> fin(n + 1);
  for (int i = n; i >= 1; i --)
    fin[i] = (i == n || a[i] != a[i + 1]) ? i : fin[i + 1];
  for (auto [l, r, x]: getv<int, int, int>(m)) {
    if (a[l] != x)
      printf("%d\n", l);
    else if (fin[l] < r)
      printf("%d\n", fin[l] + 1);
    else
      printf("-1\n");
  }
  return 0;
}
