#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector <vector<int>> g(n);
    vector <int> path;

    for (int i = 0, u, v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        path.push_back(u+v);
        g[u].push_back(i);
        g[v].push_back(i);
    }

    vector <int> dist(n, -1), dq(n);
    dist[0] = 0;
    int l = 0, r = 1;
    while (l < r){
        auto u = dq[l];
        l += 1;
        for (auto &i : g[u]){
            int v = path[i]-u;
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                dq[r] = v;
                r += 1;
            }
        }
    }

    vector <vector<int>> gs(n);
    vector <int> dg(n);
    for (int u = 0; u < n; ++ u){
        for (auto &i : g[u]){
            int v = path[i] - u;
            if (dist[v] == dist[u]+1){
                gs[v].push_back(i);
                dg[v] += 1;
            }
        }
    }

    long long cur = 1;
    for (int i = 1; i < n; ++ i){
        cur *= dg[i];
        if (cur > k){
            cur = k;
            break;
        }
    }

    int all = 0;
    auto dfs = [&](auto &&f, int u, string &res)->void{
        if (all == cur) return;
        if (u == n){
            cout << res << "\n";
            all += 1;
            return;
        }
        for (auto &i : gs[u]){
            res[i] = '1';
            f(f, u+1, res);
            res[i] = '0';
        }
    };

    cout << cur << "\n";

    string res;
    for (int i = 0; i < m; ++ i){
        res += '0';
    }

    dfs(dfs, 1, res);
}
