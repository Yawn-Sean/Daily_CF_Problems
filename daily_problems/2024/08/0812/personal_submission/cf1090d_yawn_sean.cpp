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

    set<pair<int, int>> st;

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        if (u < v) swap(u, v);
        st.emplace(make_pair(u, v));
    }

    if (m == 1ll * n * (n - 1) / 2)
        cout << "NO";
    else {
        bool flg = false;
        int x = -1, y = -1;

        for (int i = 0; i < n && !flg; i ++) {
            for (int j = 0; j < i && !flg; j ++) {
                pair<int, int> pr = {i, j};
                if (st.find(pr) == st.end()) {
                    flg = true;
                    x = i, y = j;
                }
            }
        }

        vector<int> ans(n);
        ans[x] = 1, ans[y] = 2;
        int cur = 3;

        for (int i = 0; i < n; i ++) {
            if (!ans[i]) ans[i] = cur ++;
        }

        cout << "YES\n";
        for (auto &x: ans) cout << x << ' ';
        cout << '\n';
        ans[y] = 1;
        for (auto &x: ans) cout << x << ' ';
    }

    return 0;
}