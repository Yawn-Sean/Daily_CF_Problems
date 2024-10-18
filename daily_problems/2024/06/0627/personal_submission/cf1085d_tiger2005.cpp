int main() {
  int n, s; cin >> n >> s;
  vector<int> v(n);
  for (auto [a, b]: getv<int, int>(n - 1))
    ++ v[a - 1], ++ v[b - 1];
  int leaf = count(ALL(v), 1);
  printf("%.12f", 2.0 * s / leaf);
  return 0;
}
