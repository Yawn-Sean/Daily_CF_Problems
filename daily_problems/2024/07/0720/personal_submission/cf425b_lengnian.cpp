#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

int a[102][102];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }

    int ans = 500;
    if (n <= k)
    {
        for (int o = 0; o < (1 << n); o++)
        {
            int res = 0;
            for (int j = 0; j < m; j++)
            {
                int dif = 0;
                for (int i = 0; i < n; i++)
                {
                    if (((o & (1 << i)) > 0) != a[i][j])
                        ++dif;
                }
                dif = min(dif, n - dif);
                res += dif;
            }
            ans = min(ans, res);
        }
    }
    else
    {
        for (int t = 0; t < n; t++)
        {
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                int dif = 0;
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] != a[t][j])
                        ++dif;
                }
                res += min(dif, m - dif);
            }
            ans = min(ans, res);
        }
    }
    if (ans > k)
        ans = -1;
    cout << ans << "\n";
    return 0;
}
