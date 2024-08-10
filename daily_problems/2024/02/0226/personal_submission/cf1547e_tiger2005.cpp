int main() {
  multiCase() {
    int n, k; cin >> n >> k;
    vector<int> ac(n + 1, 1.5e9);

    auto A = getv(k);
    auto B = getv(k);
    for (int i = 0; i < k; i ++)
      ckmin(ac[A[i]], B[i]);

    vector<int> ans(n + 1, 2e9);
    int L = 1.5e9;
    for (int i = 1; i <= n; i ++) {
      L = min(L + 1, ac[i]);
      ckmin(ans[i], L);
    }
    L = 1.5e9;
    for (int i = n; i; i --) {
      L = min(L + 1, ac[i]);
      ckmin(ans[i], L);
    }
    write(ans, 1, n, "%d ", "\n");
  }
  return 0;
}
