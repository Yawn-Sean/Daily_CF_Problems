#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 1e18;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector <i64> siz(n, 1), dis_sum(n), dep(n), ord_L(n), ord_R(n);
    vector<vector<int>> g(n), who(n), st(n, vector<int>(20, -1));
    vector <f64> ans(m);
    vector <array<int,2>> asks;

    for (int i = 0, u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // process siz, dfs-order, multiplication-table, distance contribution on node
    int snap = 0;
    auto dfs_process = [&](auto &&self, int u, int presor)->void{
        ord_L[u] = ++ snap;
        for (auto &v : g[u]){
            if (v == presor) continue;
            dep[v] = dep[u] + 1, st[v][0] = u;
            for (int i = 1; i < 20; ++ i){
                if (st[v][i-1] == -1) break;
                st[v][i] = st[st[v][i-1]][i-1];
            }

            self(self, v, u);
            siz[u] += siz[v];
            dis_sum[u] += dis_sum[v] + siz[v];
        }
        ord_R[u] = snap;
    };
    dfs_process(dfs_process, 0, -1);


    // process query
    for (int i = 0, u, v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        if (ord_L[u] > ord_L[v]) swap(u, v);

        asks.push_back({u, v});
        who[u].push_back(i);
    }

    // multiplication-table
    auto jump_up = [&](int u, int dep)->int{
        for (int i = 19; i >= 0; -- i){
            if (dep>>i & 1){
                u = st[u][i];
            }
        }
        assert(u != -1);
        return u;
    };
    auto lca = [&](int u, int v)->int{
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 0, d = dep[u]-dep[v]; i < 20; ++ i){
            if (d>>i & 1){
                u = st[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; -- i){
            if (st[u][i] != st[v][i]){
                u = st[u][i], v = st[v][i];
            }
        }
        return st[u][0];
    };
    auto Dis = [&](int u, int v)->int{
        return dep[u]+dep[v] - 2*dep[lca(u, v)];
    };
    // deal query on each node
    auto dfs_deal = [&](auto &&self, int u, int presor, i64 fa_siz, i64 fa_dis_sum)->void{
    
        for (auto &id : who[u]){
            int v = asks[id][1];
            if (ord_L[v] <= ord_R[u]){
                int son_u = jump_up(v, dep[v]-dep[u]-1);

                i64 all1 = n - siz[son_u], all2 = siz[v];
                i64 all = all1 * all2, son_dis_sum = dis_sum[u]-(dis_sum[son_u]+siz[son_u]);

                i64 dis_uv = dep[v]-dep[u];

                ans[id] = 1.0 * (all2*(fa_dis_sum+son_dis_sum) + all1*dis_sum[v]) / all + dis_uv + 1;
            } else {
                i64 all = siz[u] * siz[v];
                i64 dis_uv = Dis(u, v);
                ans[id] = 1.0 * (siz[v]*dis_sum[u] + siz[u]*dis_sum[v]) / all + dis_uv + 1;
            }
        }

        for (auto &v : g[u]){
            if (v == presor) continue;
            i64 nxt_fa_siz = siz[u]-siz[v] + fa_siz;
            i64 nxt_fa_dis_sum = (fa_dis_sum+fa_siz) + (dis_sum[u]-dis_sum[v]+siz[u]-2*siz[v]);
            self(self, v, u, nxt_fa_siz, nxt_fa_dis_sum);
        }

    };
    dfs_deal(dfs_deal, 0, -1, 0, 0);
    cout << fixed << setprecision(15);
    for (int i = 0; i < m; ++ i){
        cout << ans[i] << "\n";
    }
}
