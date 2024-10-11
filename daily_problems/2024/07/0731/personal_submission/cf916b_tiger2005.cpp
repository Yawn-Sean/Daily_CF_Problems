int main() {
  i64 n; int k;
  cin >> n >> k;
  if (__builtin_popcountll(n) > k)
    return puts("No"), 0;
  puts("Yes");
  vector<int> ans;
  if (n < k) {
    int u = 0;
    while (2 * n <= k)
      n *= 2, -- u;
    while (n --)
      ans.push_back(u);
  }
  else {
    int cur = k;
    i64 num = n;
    {
      int l = -1, r = 64 - __builtin_clzll(num);
      while (l < r - 1) {
        int m = (l + r) >> 1;
        i64 cnt = num >> m;
        i64 tmp = num & ((1ll << m) - 1);
        if (__builtin_popcountll(tmp) <= cur - cnt)
          r = m;
        else
          l = m;
      }
      for (; r >= 0; r --)
        while (num >= (1ll << r))
          ans.push_back(r), num -= 1ll << r, -- cur;
    }
  }

  while ((int)ans.size() != k) {
    int u = ans.back();
    ans.pop_back();
    ans.push_back(u - 1);
    ans.push_back(u - 1);
  }
  write(ans, "%d ");

  return 0;
}
