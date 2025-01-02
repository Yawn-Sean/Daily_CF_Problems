#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;
    using ary3 = array<int,3>;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(m+1);

    vector <ary2> ps(n);
    vector <ary3> fences(m+1);
    for (auto &p : ps){
        cin >> p[0] >> p[1];
    }

    for (int i = 1; i <= m; ++ i){
        auto &fe = fences[i];
        cin >> fe[2] >> fe[0] >> fe[1];
    }

    auto chk_fa = [&](int x, int u)->bool{
        i64 d_r = 1ll*(fences[x][2] - fences[u][2]) * (fences[x][2] - fences[u][2]);
        i64 d_dis = 1ll*(fences[x][0]-fences[u][0])*(fences[x][0]-fences[u][0])
        + 1ll*(fences[x][1]-fences[u][1])*(fences[x][1]-fences[u][1]);
        return fences[x][2] < fences[u][2] && d_dis < d_r;
    };
    auto chk_point = [&](const ary2 &p, const ary3 &fence)->bool{
        i64 d_r = 1ll * fence[2] * fence[2];
        i64 d_dis = 1ll*(p[0]-fence[0])*(p[0]-fence[0]) + 1ll*(p[1]-fence[1])*(p[1]-fence[1]);
        return d_dis < d_r;
    };
    // create graph
    for (int i = 1; i <= m; ++ i){
        int presor = 0;
        for (int j = 1; j <= m; ++ j){
            if (i == j) continue;
            if (chk_fa(i, j)){
                if (presor == 0 || fences[j][2] < fences[presor][2]){
                    presor = j;
                }
            }
        }
        g[presor].push_back(i);
    }
    // locates control points
    vector <int> locs(n);
    vector <int> stk = {0};
    while (!stk.empty()){
        auto u = stk.back();
        stk.pop_back();
        for (auto &v : g[u]){
            for (int j = 0; j < n; ++ j){
                if (chk_point(ps[j], fences[v])){
                    locs[j] = v;
                }
            }
            stk.push_back(v);
        }
    }

    // multiplication algorithm
    vector<vector<int>> st(m+1, vector<int>(20, -1));
    vector <int> dep(m+1);
    auto dfs_find = [&](auto &&self, int u)->void{
        for (auto &v : g[u]){
            dep[v] = dep[u] + 1, st[v][0] = u;
            for (int j = 1; j < 20; ++ j){
                if (st[v][j-1] == -1) break;
                st[v][j] = st[st[v][j-1]][j-1];
                // cout << v << " " << j-1 << "\n";
            }
            self(self, v);
        }
    };
    dfs_find(dfs_find, 0);
    auto lca = [&](int x, int y)->int{
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = 0, d = dep[x]-dep[y]; 1<<i <= d; ++ i){
            if (d>>i & 1){
                x = st[x][i];
            }
        }
        if (x == y) return x;
        for (int i = 20; i >= 0; -- i){
            if (st[x][i] != st[y][i]){
                x = st[x][i], y = st[y][i];
            }
        }
        return st[x][0];
    };
    auto Dis = [&](int x, int y)->int{
        return dep[x]+dep[y] - 2*dep[lca(x,y)];
    };
    // solve query
    for (int i = 0, u,v; i < k; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        cout << Dis(locs[u], locs[v]) << "\n";
    }
}
