int main() {
  multiCase() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<bool> cov(n), coh(m);
    Z ans = 1, cx = 0, cy = 0;
    for (auto [x, y]: reversed(getv<int, int>(q))) {
      -- x, -- y;
      if (!cov[x] || !coh[y]) {
        cx += !cov[x];
        cy += !coh[y];
        cov[x] = coh[y] = true;
        ans *= k;
        if (cx == n || cy == m)
          break;
      }
    }
    printf("%d\n", (int)ans);
  }
  return 0;
}
