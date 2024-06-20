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
// #define int long long
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool st[510][510];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
            if (a[i][j] == '1')
            {
                bool res = true;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (a[x][y] != '1')
                    {
                        res = false;
                        break;
                    }
                }

                st[i][j] = res;
            }
    }

    i64 ans = 0;
    vector<int> b(n);
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j = 0; j < m; j++)
            b[j] = 0;
        for (int j2 = j1 + 1; j2 < n; j2++)
        {
            int cur = 0, r = 1;
            for (int l = 0; l < m; l++)
            {
                cur -= b[l];
                while (r < m && cur < k)
                {
                    cur += b[r];
                    r++;
                }

                ans += m - r;
            }
            for (int g = 0; g < m; g++)
            {
                b[g] += st[j2][g];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
