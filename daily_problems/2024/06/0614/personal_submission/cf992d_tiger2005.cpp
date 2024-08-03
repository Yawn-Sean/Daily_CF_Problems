int main() {
  int n, k; cin >> n >> k;
  auto a = getv(n);
  vector<pair<int, int>> vp;
  int one_count = 0;
  int ans = 0;
  
  for (int i = n - 1; i >= 0; i --) {
    if (a[i] == 1)
      ++ one_count;
    else {
      vp.emplace_back(a[i], one_count);
      one_count = 0;
    }
    long long sm = one_count, prod = 1;
    if (one_count && k == 1)
      ++ ans;
    for (int j = (int)vp.size() - 1; j >= 0; j --) {
      auto [num, ones] = vp[j];
      if (INF / prod < num)
        break;
      prod *= num;
      // sum should be in [sm + num, sm + num + ones]
      if (prod % k == 0 && sm + num <= prod / k && prod / k <= sm + num + ones)
        ++ ans;
      sm += num + ones;
    }
  }
  printf("%d\n", ans);
}
