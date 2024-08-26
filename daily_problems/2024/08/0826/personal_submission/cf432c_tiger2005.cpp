vector<int> s[100010];

int main() {
  int n; cin >> n;
  auto a = getv(n, 1);
  vector<int> pos(n + 1);
  for (auto [i, e]: index(a))
    pos[e] = i;

  vector<pair<int, int>> ans;
  auto go = [&] (int i, int j) {
    swap(pos[a[i]], pos[a[j]]);
    swap(a[i], a[j]);
    ans.emplace_back(i, j);
  };

  auto p = getPrimes(n + 1);
  for (int i = 1; i <= n; i ++) {
    auto ptr = upper_bound(ALL(p), i + 1) - 1;
    while (1) {
      if (i == *ptr - 1 || s[i - *ptr + 1].size() != 0) {
        s[i] = s[i - *ptr + 1];
        s[i].push_back(*ptr - 1);
        break;
      }
      -- ptr;
    }
  }

  for (int i = 1; i < n; i ++) {
    int j = pos[i];
    for (auto e: s[j - i]) {
      go(j - e, j);
      j -= e;
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto [a, b]: ans)
    printf("%d %d\n", a, b);
  return 0;
}
