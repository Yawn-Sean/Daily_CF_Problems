#include <bits/stdc++.h>
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    long long ans = 0;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= m; j ++)
            if ((i * i + j * j) % m == 0)
                ans += 1ll * ((n + m - i) / m) * ((n + m - j) / m);
    
    cout << ans << '\n';

    return 0;
}