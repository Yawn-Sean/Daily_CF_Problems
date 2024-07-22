#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(n, 1);
    int ans = n, mod = 998244353;

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        ans = 1ll * ans * cnt[u] % mod * cnt[v] % mod;
        cnt[u] ++, cnt[v] ++;
    }
    cout << ans;

    return 0;
}