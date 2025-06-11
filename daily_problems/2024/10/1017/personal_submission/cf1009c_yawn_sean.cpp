#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    long long v1 = 1ll * n * (n - 1) / 2, v2 = 0;
    for (int i = 0; i < n; i ++)
        v2 += abs(i - n / 2);

    int ans = 0;
    long long tot = 0;
    while (q --) {
        int x, y;
        cin >> x >> y;
        ans += x;
        tot += (y >= 0 ? v1 : v2) * y;
    }

    cout << setprecision(20) << (long double)tot / n + ans;

    return 0;
}