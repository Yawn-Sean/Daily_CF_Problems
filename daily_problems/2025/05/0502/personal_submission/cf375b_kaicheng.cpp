#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<string> grid(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> grid[i];
    grid[i] = " " + grid[i];
  }

  vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= 1; j--)
    {
      if (grid[i][j] == '1')
      {
        dp[i][j] = dp[i][j + 1] + 1;
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }

  for (int j = 1; j <= m; j++)
  {
    vector<int> col(n);
    for (int i = 1; i <= n; i++)
    {
      col[i - 1] = dp[i][j];
    }

    sort(col.rbegin(), col.rend());

    for (int i = 0; i < n; i++)
    {
      ans = max(ans, (i + 1) * col[i]);
    }
  }

  cout << ans << '\n';
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  while (tt--)
  {
    solve();
  }
  return 0;
}