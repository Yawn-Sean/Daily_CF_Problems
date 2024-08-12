#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int d, mod, tmp = 1;
        cin >> d >> mod;
        long long ans = 1;
        while (tmp <= d) {
            ans = ans * (min(tmp, d - tmp + 1) + 1) % mod;
            tmp <<= 1;
        }
        cout << (ans - 1 + mod) % mod << '\n';
    }

    return 0;
}