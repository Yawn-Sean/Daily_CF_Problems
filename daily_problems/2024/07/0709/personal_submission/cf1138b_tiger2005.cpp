
int main() {
  int n; cin >> n;
  auto c = getv<char>(n);
  auto a = getv<char>(n);
  int X = accumulate(ALL(a), 0, [&] (int i, char j) {
    return i + j - '0';
  });
  vector<vector<int>> vec(3);
  for (int i = 0; i < n; i ++)
    vec[a[i] - '0' + c[i] - '0'].push_back(i + 1);
  for (int A2 = 0; A2 <= (int)vec[2].size() && X >= 0; A2 ++, X -= 2) {
    if ((int)vec[1].size() < X)
      continue;
    if (X + A2 > n / 2 || X + A2 + (int)vec[0].size() < n / 2)
      continue;
    for (auto [idx, val]: vector<pair<int, int>>{{0, n / 2 - X - A2}, {1, X}, {2, A2}})
      for (int i = 0; i < val; i ++)
        printf("%d ", vec[idx][i]);
    return 0;
  }
  puts("-1");
  return 0;
}
