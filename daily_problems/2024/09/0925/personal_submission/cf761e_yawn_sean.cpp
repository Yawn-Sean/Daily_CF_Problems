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

    int n;
    cin >> n;

    vector<vector<int>> path(n);

    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    for (int i = 0; i < n; i ++) {
        if (path[i].size() > 4) {
            return cout << "NO", 0;
        }
    }

    vector<pair<int, int>> pos(n);
    vector<int> used(n);

    pos[0] = {0, 0};
    used[0] = 1;

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<array<int, 3>> stk;

    stk.push_back({0, -1, 1 << 29});

    while (!stk.empty()) {
        auto [u, nd, msk] = stk.back();
        stk.pop_back();

        int cur_d = 0;
        msk >>= 1;

        for (auto &v: path[u]) {
            if (used[v] == 0) {
                used[v] = 1;

                if (cur_d == nd) cur_d ++;
                auto [dx, dy] = dirs[cur_d];

                pos[v].first = pos[u].first + dx * msk;
                pos[v].second = pos[u].second + dy * msk;

                stk.push_back({v, cur_d ^ 2, msk});
                cur_d ++;
            }
        }
    }

    cout << "YES\n";
    for (auto &[x, y]: pos)
        cout << x << ' ' << y << '\n';

    return 0;
}