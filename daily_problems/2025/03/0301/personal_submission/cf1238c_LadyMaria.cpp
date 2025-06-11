void solve()
{
  int h, n;
  cin >> h >> n;

  VI a(n + 1);
  cin >> a;

  int ans{};
  For(i, 1, n)
  {
    if (i + 2 <= n)
    {
      if (a[i + 2] == a[i + 1] - 1)
        i++;
      else
      {
        ans++;
      }
    }
    else
    {
      if (a[i + 1] > 1)
      {
        ans++;
        break;
      }
    }
  }

  cout << ans << '\n';
}
