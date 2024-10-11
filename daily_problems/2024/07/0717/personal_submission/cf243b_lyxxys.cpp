#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2050, mod = 1070777777, inf = 1e9;

void solve(){
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    vector <vector<int>> g(n+1);
    vector <int> deg(n+1);
    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
        ++ deg[a], ++ deg[b];
    }

    vector <int> has(n+1);
    auto check = [&](int u, int v)->bool{
        if (deg[u] < h+1 || deg[v] < t+1) return false;
        // 设定一个上界limit,并贪心处理交集
        int limit = h+t;
        vector <int> ans1, ans2;
        int tot = 0, ct = 0;
        for (auto &x : g[u]){
            if (x == v) continue;
            has[x] |= 1, ++ tot, ++ ct;
            if (ct > limit) break;
        }
        ct = 0;
        for (auto &x : g[v]){
            if (x == u) continue;
            has[x] |= 2;
            ++ ct;
            if (has[x] == 2) ++ tot;
            if (ct > limit) break;
        }

        if (tot < h+t){
            for (auto &x : g[u]) has[x] = 0;
            for (auto &x : g[v]) has[x] = 0;
            return false;
        }
        for (auto &x : g[u]){
            if (h && has[x] == 1) -- h, ans1.push_back(x);
        }
        for (auto &x : g[v]){
            if (t && has[x] == 2) -- t, ans2.push_back(x);
        }
        for (auto &x : g[v]){
            if (!t && !h) break;
            if (has[x] == 3){
                if (h) -- h, ans1.push_back(x);
                else -- t, ans2.push_back(x);
            }
        }
        cout << "YES\n";
        cout << u << " " << v << "\n";
        for (auto &x : ans1) cout << x << " ";
        cout << "\n";
        for (auto &x : ans2) cout << x << " ";
        cout << "\n";
        return true;
    };

    for (int u = 1; u <= n; ++ u){
        for (auto &x : g[u]){
            if (check(u, x)) return;
        }
    }
    cout << "NO\n";
}
