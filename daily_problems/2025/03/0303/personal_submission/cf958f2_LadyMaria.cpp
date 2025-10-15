void solve()
{
  int n, m;
  while (cin >> n >> m)
  {
    VI a(n + 1), K(m + 1);
    cin >> a >> K;

    int sum{};
    For1(i, 1, m) sum += K[i];

    VI cnt(n + 1);
    int idx = 1, ans = INF;

    for (int i = 1, j = 1; j <= n; ++j)
    {
      cnt[a[j]]++;
      if (idx < m + 1)
      {
        while (idx <= m && cnt[idx] >= K[idx])
          idx++;
        if (idx < m + 1)
          continue;
      }

      while (i < j && cnt[a[i]] - 1 >= K[a[i]])
      {
        cnt[a[i]]--;
        i++;
      }
      ckmin(ans, j - i + 1 - sum);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
  }
}
