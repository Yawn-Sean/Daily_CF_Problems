#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

int c[N];
LL s[N];
LL f[40][N];

int dp(int h, int w, int a, int b, int pos)
{
    n = pos;
    s[0] = 1ll * h * w;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] * c[i];
    for (int j = 0; j <= a; j++)
    {
        if (j <= h)
            f[0][j] = h;
        else
            f[0][j] = 1e18;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= a; j++)
        {
            f[i][j] = f[i - 1][j];
            if (f[i - 1][(j + c[i] - 1) / c[i]] != 1e18)
                f[i][j] = min(f[i][j], f[i - 1][(j + c[i] - 1) / c[i]] * c[i]);
        }

    for (int i = 0; i <= n; i++)
    {
        if ((s[i] + f[i][a] - 1) / f[i][a] >= b)
        {
            return i;
        }
    }

    return -1;
}
void solve()
{
    int a, b, h, w;
    cin >> a >> b >> h >> w >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c + 1, c + 1 + n, [&](int A, int B)
         { return A > B; });

    LL v = 1, pos = n;
    for (int i = 1; i <= n; i++)
    {
        v *= c[i];
        if (v >= 1e10)
        {
            pos = i;
            break;
        }
    }

    int ans = dp(h, w, a, b, pos);
    ans = min(ans, dp(w, h, a, b, pos));
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
