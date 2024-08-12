int main() {
  multiCase() {
    int n; cin >> n;
    BIT<int> a(n, 0, [&] (int a, int b) {
      return a + b;
    });
    vector<int> freq(n + 1);
    int ans = 0;
    for (auto e: getv(n)) {
      ans ^= a.query(n) - a.query(e);
      a.apply(e, 1);
      ++ freq[e];
    }
    YON(ans % 2 == 0 || *max_element(ALL(freq)) > 1, "\n");
  }
  return 0;
}
