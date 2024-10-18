#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    int ans = n;
    while (q --) {
        int l, r;
        cin >> l >> r;
        ans = min(ans, r - l + 1);
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i ++)
        cout << i % ans << ' ';

    return 0;
}