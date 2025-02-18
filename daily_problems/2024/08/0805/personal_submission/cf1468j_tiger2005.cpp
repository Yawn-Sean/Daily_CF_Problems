int main() {
  multiCase() {
    int n, m, k;
    cin >> n >> m >> k;
    Union un(n);
    auto e = getv<int, int, int>(m);
    sort(e, [&] (auto a, auto b) {
      return get<2>(a) < get<2>(b);
    });

    i64 ans1 = 1e18, ans2 = 0;
    for (auto [a, b, c]: e) {
      ckmin(ans1, abs(c - k));
      if (un[a] != un[b])
        un.link(a, b), ans2 += max(c - k, 0);
    }
    printf("%lld\n", ans2 ? ans2 : ans1);
  }
  return 0;
}
