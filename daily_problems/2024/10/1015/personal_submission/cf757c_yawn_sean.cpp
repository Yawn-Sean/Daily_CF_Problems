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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tmp(m);

    for (int i = 0; i < n; i ++) {
        int g;
        cin >> g;
        while (g --) {
            int x;
            cin >> x;
            tmp[x - 1].emplace_back(i);
        }
    }

    sort(tmp.begin(), tmp.end());

    int cur = 1, ans = 1, mod = 1e9 + 7;
    for (int i = 1; i < m; i ++) {
        if (tmp[i] == tmp[i - 1]) cur ++;
        else cur = 1;
        ans = 1ll * ans * cur % mod;
    }
    cout << ans;

    return 0;
}