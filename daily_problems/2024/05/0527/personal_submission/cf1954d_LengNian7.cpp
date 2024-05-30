#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 mod = 998244353;
const int N = 5005;

int a[N];
i64 f[N];

signed main()
{
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]), m += a[i];
    }
    sort(a + 1, a + n + 1);
    i64 ans = 0;
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j <= m - a[i]; j ++ )
        {
            ans += (a[i] > j ? a[i] : (j + a[i] + 1) / 2) * f[j] % mod;
            ans %= mod;
        }

        for (int j = m; j >= a[i]; j -- )
        {
            f[j] = (f[j] + f[j - a[i]]) % mod;
        }
    }

    printf("%lld\n", ans);

    return 0;

}
