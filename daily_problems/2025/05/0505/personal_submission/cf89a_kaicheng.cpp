#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  int cnt = LLONG_MAX;
  for (int i = 0; i < n; i += 2)
  {
    cnt = min(cnt, a[i]);
  }

  int ans = 0;
  int need = n / 2 + 1;

  if (n % 2 != 0 && need <= m)
  {
    ans = (m / need) * k;
    ans = min(cnt, ans);
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