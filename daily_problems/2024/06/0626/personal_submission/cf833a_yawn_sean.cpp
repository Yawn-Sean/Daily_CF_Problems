#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t --) {
        int a, b;
        cin >> a >> b;
        long long mul = 1ll * a * b;
        int l = 1, r = 1e6;
        while (l <= r) {
            int m = (l + r) / 2;
            if (1ll * m * m * m > mul) r = m - 1;
            else l = m + 1;
        }
        cout << (1ll * r * r * r == mul && a % r == 0 && b % r == 0 ? "Yes\n" : "No\n");
    }

    return 0;
}