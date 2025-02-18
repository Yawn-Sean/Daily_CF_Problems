int main() {
  int n, h; cin >> n >> h;
  auto v = getv<pair<int, int>>(n);
  int sm = 0, ans = 0;
  for (int l = n - 1, r = n - 1; l >= 0; l --) {
    sm += v[l].second - v[l].first;
    while (1) {
      sm -= v[r].second - v[r].first;
      if (h - (v[r].first - v[l].first - sm) <= 0)
        -- r;
      else
        break;
    }
    sm += v[r].second - v[r].first;

    ckmax(ans, h + sm);
  }
  printf("%d", ans);
  return 0;
}
