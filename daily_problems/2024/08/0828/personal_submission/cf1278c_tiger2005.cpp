int main() {
  multiCase() {
    int n; cin >> n;
    auto v = getv(2 * n);
    map<int, int> q;
    q[0] = 0;
    for (int i = 0, tmp = 0; i < n; i ++) {
      tmp += v[i] == 1 ? 1 : -1;
      q[tmp] = i + 1;
    }
    int ans = q[0];
    for (int i = 0, tmp = 0; i < n; i ++) {
      tmp += v[2 * n - 1 - i] == 1 ? 1 : -1;
      if (q.find(- tmp) != q.end())
        ckmax(ans, i + 1 + q[- tmp]);
    }
    printf("%d\n", 2 * n - ans);
  }
  return 0;
}
