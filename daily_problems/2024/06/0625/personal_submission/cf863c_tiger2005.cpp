int main() {
  auto [n, a, b] = reads<i64, i32, i32>();
  auto F = getv<array<int, 3>>(3);
  auto G = getv<array<int, 3>>(3);
  auto win = [&] (int x, int y) {
    return (x + 3 - y) % 3 == 1;
  };
  long long ans1 = 0, ans2 = 0;
  map<pair<int, int>, int> mp;
  vector<pair<int, int>> vp;
  int mrk = 0, cyc = 0;
  for (int i = 1; i <= 10; i ++) {
    if (mp[{a, b}]) {
      mrk = mp[{a, b}] - 1;
      cyc = i - mp[{a, b}];
      break;
    }
    mp[{a, b}] = i;
    vp.emplace_back(a, b);
    tie(a, b) = {
      F[a - 1][b - 1],
      G[a - 1][b - 1]
    };
  }
  for (int i = 0; i < mrk && n != 0; i ++) {
    -- n;
    ans1 += win(vp[i].first, vp[i].second);
    ans2 += win(vp[i].second, vp[i].first);
  }
  long long cnt = n / cyc;
  n %= cyc;
  for (int i = mrk; n != 0; i ++) {
    -- n;
    ans1 += win(vp[i].first, vp[i].second);
    ans2 += win(vp[i].second, vp[i].first);
  }
  for (int i = mrk; i < (int)vp.size(); i ++) {
    ans1 += cnt * win(vp[i].first, vp[i].second);
    ans2 += cnt * win(vp[i].second, vp[i].first);
  }
  printf("%lld %lld", ans1, ans2);
  return 0;
}
