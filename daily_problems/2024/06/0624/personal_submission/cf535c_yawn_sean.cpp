#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    while (n --) {
        int l, t, m;
        cin >> l >> t >> m;
        long long left = l, right = l + 1ll * t * m;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (((a + (l - 1) * b + a + (mid - 1) * b) * (mid - l + 1) / 2 > 1ll * t * m) || (a + (mid - 1) * b > t))
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout << (right >= l ? right : -1) << '\n';
    }

    return 0;
}