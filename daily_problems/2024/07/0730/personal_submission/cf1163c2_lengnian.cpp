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

const int N = 1010;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

pair<pii, int> p[N * N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int m = 0;

    int a[N]{};
    int b[N]{};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x = a[i] - a[j];
            int y = b[i] - b[j];

            if (x < 0)
            {
                x = -x;
                y = -y;
            }
            int z = gcd(x, y);
            x /= z;
            y /= z;
            p[++m] = {{x, y},
                      b[i] * x - a[i] * y};
        }
    }

    sort(p + 1, p + m + 1);
    m = unique(p + 1, p + m + 1) - p - 1;
    int ans = m * (m - 1ll) / 2;
    p[0] = p[m + 1] = {{-1, -1}, -1};
    for (int i = 1, j = 0; i <= m + 1; i++)
    {
        if (p[i - 1].fi != p[i].fi)
        {
            ans -= j * (j - 1ll) / 2;
            j = 1;
        }
        else
        {
            j++;
        }
    }
    cout << ans << "\n";

    return 0;
}
