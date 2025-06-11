int main() {
  int n; cin >> n;
  Z ans = 0;
  vector<int> siz(11);
  vector<vector<int>> v;
  for (auto e: getv(n)) {
    vector<int> tmp;
    while (e)
      tmp.push_back(e % 10), e /= 10;
    v.emplace_back(tmp);
    ++ siz[tmp.size()];
  }
  for (int i = 0; i < n; i ++) {
    int l = v[i].size();
    for (int j = 0; j < l; j ++) {
      for (int k = 1; k <= 10; k ++) {
        Z coef = Z(10).pow(j + min(j, k)) + Z(10).pow(j + min(j + 1, k));
        ans += coef * v[i][j] * siz[k];
      }
    }
  }
  printf("%d", (int)ans);
  return 0;
}
