int main() {
  int n; cin >> n;
  vector<long long> k(2 * n + 1), b(2 * n + 1), ans(n);
  for (auto [i, x]: index(getv(n))) {
    -- x;
    int l = n + x - i;
    int r = 2 * n - 1 - i;
    ++ k[l], -- k[r + 1];
    b[l] -= l, b[r + 1] += l;
  }
  long long sk = 0, sb = 0;
  for (int i = 0; i < 2 * n; i ++) {
    sk += k[i];
    sb += b[i];
    ans[i % n] += sk * i + sb;
  }
  auto ptr = min_element(ALL(ans));
  cout << (*ptr) * 2 << ' ' << ptr - ans.begin();
  return 0;
}
