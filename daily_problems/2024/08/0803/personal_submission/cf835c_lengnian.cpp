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

int cnt[11][110][110] = {0};

int init(int p, int x1, int y1, int x2, int y2)
{
    return cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, c;
    cin >> n >> q >> c;

    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cnt[z][x][y]++;
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                cnt[k][i][j] += cnt[k][i - 1][j] + cnt[k][i][j - 1] - cnt[k][i - 1][j - 1];
            }
        }
    }
    while (q--)
    {
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int p = 0; p <= c; p++)
        {
            int b = (p + t) % (c + 1);
            ans += b * init(p, x1, y1, x2, y2);
        }
        cout << ans << "\n";
    }
}
