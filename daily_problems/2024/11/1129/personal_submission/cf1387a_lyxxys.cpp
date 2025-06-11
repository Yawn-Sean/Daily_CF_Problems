#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;

    int n, m;
    cin >> n >> m;
    vector <ary2> uvs;
    vector<vector<int>> g(n);
    vector<long double> ans(n);
    for (int i = 0, u,v,w; i < m; ++ i){
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        g[u].push_back(i), g[v].push_back(i);
        uvs.push_back({u^v, w});
    }

    vector <int> poly_k(n), poly_b(n);  // 维护一次项系数 k 和 常数项 b

    for (int i = 0; i < n; ++ i){
        if (poly_k[i] != 0) continue;

        vector <int> vts;
        vector <array<int,3>> egs;
        bool jg = 0;
        long double x;
        auto dfs = [&](auto &&self, int u)->void{
            vts.push_back(u);
            for (auto &i : g[u]){
                int v = uvs[i][0]^u, w = uvs[i][1];
                egs.push_back({u, v, w});
                if (!poly_k[v]){
                    poly_k[v] = -poly_k[u];
                    poly_b[v] = w - poly_b[u];
                    self(self, v);
                } else if (poly_k[v] == poly_k[u]) {
                    jg = 1;
                    x = 1.0 * (w - (poly_b[v]+poly_b[u])) / (2*poly_k[u]);
                }
            }
        };

        poly_k[i] = 1, poly_b[i] = 0;
        dfs(dfs, i);

        if (!jg){
            int len = vts.size();
            sort(vts.begin(), vts.end(), [&](int &u, int &v){
                return -poly_k[u] * poly_b[u] < -poly_k[v] * poly_b[v];
            });  // 中位数贪心
            x = - poly_k[vts[len/2]] * poly_b[vts[len/2]];
        }

        for (auto &u : vts){
            ans[u] = poly_k[u] * x + poly_b[u];
        }

        for (auto &it : egs){
            long double u = it[0], v = it[1], w = it[2];
            if (fabs(ans[u]+ans[v] - w) > 0.01){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    cout << fixed << setprecision(15);
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
}
