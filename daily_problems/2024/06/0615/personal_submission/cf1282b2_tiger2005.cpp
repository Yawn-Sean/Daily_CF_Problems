int main() {
  multiCase() {
    int n, p, k; cin >> n >> p >> k;
    auto a = sorted(getv(n));
    int ans = 0;
    long long cur = 0;
    for (int i = 0; i < k; i ++) {
      if (i)
        cur += a[i - 1];
      long long tmp = cur;
      int cnt = i, ptr = k + i - 1;
      while (tmp <= p) {
        ans = max(ans, cnt);
        cnt += k;
        if (ptr >= n)
          break;
        tmp += a[ptr];
        ptr += k;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
