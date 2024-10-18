#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, mod = 998244353;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;

        vector<int> perm(n);
        for (auto &x: perm) cin >> x, x --;

        vector<int> pos(n);
        for (int i = 0; i < n; i ++)
            pos[perm[i]] = i;
        
        vector<int> chosen(n, 0), target(k);
        for (int i = 0; i < k; i ++) {
            cin >> target[i];
            target[i] = pos[target[i] - 1];
            chosen[target[i]] = 1;
        }

        vector<int> pre(n), nex(n);
        iota(pre.begin(), pre.end(), -1);
        iota(nex.begin(), nex.end(), 1);

        int ans = 1;

        function<void(int)> f = [&] (int x) {
            if (pre[x] >= 0) nex[pre[x]] = nex[x];
            if (nex[x] < n) pre[nex[x]] = pre[x];
        };

        for (auto &x: target) {
            int cnt = 0;
            if (pre[x] >= 0 && !chosen[pre[x]]) cnt ++;
            if (nex[x] < n && !chosen[nex[x]]) cnt ++;
            if (!cnt) {
                ans = 0;
                break;
            }
            ans = ans * cnt % mod;
            f(x);
        }
        cout << ans << '\n';
    }

    return 0;
}