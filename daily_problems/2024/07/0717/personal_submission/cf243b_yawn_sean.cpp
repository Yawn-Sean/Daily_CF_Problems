#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, h, t;
    cin >> n >> m >> h >> t;

    vector<vector<int>> path(n);

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> used(n);

    function<bool(int, int)> check = [&] (int u, int v) -> bool {
        if (path[u].size() <= h || path[v].size() <= t) return false;

        int cnt = 0;
        used[u] = used[v] = -1;

        for (auto &i: path[u]) {
            if (!used[i]) cnt ++;
            used[i] |= 1;
        }
        
        for (auto &i: path[v]) {
            if (!used[i]) cnt ++;
            used[i] |= 2;
        }

        if (cnt >= h + t) {
            vector<int> ans_u, ans_v;

            for (auto &i: path[u])
                if (h && used[i] == 1)
                    h --, ans_u.push_back(i);
            for (auto &i: path[v])
                if (t && used[i] == 2)
                    t --, ans_v.push_back(i);
            for (auto &i: path[u])
                if (used[i] == 3)
                    if (h) h --, ans_u.push_back(i);
                    else if (t) t --, ans_v.push_back(i);
            
            cout << "YES\n";
            cout << u + 1 << ' ' << v + 1 << '\n';
            for (auto &x: ans_u) cout << x + 1 << ' '; 
            cout << '\n';
            for (auto &x: ans_v) cout << x + 1 << ' '; 
            return true;
        }
        for (auto &i: path[u]) used[i] = 0;
        for (auto &i: path[v]) used[i] = 0;
        return false;
    };

    for (int u = 0; u < n; u ++)
        for (auto v: path[u])
            if (check(u, v)) return 0;

    cout << "NO";
    return 0;
}