#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, mod = 998244353;
    cin >> t;

    vector<bool> vis1(2e5), vis2(2e5);
    while (t --) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> xs(q), ys(q);
        for (int i = 0; i < q; i ++) {
            cin >> xs[i] >> ys[i];
            xs[i] --, ys[i] --;
        }
        int c1 = 0, c2 = 0, ans = 1;
        for (int i = q - 1; i >= 0; i --) {
            if ((!vis1[xs[i]] && c2 < m) || (!vis2[ys[i]] && c1 < n)) {
                ans = 1ll * ans * k % mod;
                if (!vis1[xs[i]])
                    vis1[xs[i]] = 1, c1 ++;
                if (!vis2[ys[i]])
                    vis2[ys[i]] = 1, c2 ++;
            }
        }
        for (auto &x: xs) vis1[x] = 0;
        for (auto &y: ys) vis2[y] = 0;
        cout << ans << '\n';
    }

    return 0;
}