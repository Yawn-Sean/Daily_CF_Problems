#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> struct fenwick {
    vector <T> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void update(int x, T val){
        if (x > n || x <= 0) return;
        while (x <= n){
            info[x] += val;
            x += x&-x;
        }
    }
    T query(int x){
        T res = 0;
        while (x){
            res += info[x];
            x -= x&-x;
        }
        return res;
    }
    T query(int lo, int hi){
        return query(hi) - query(lo);
    }
    T select(T kth){
        T ans = 0, lst = 0;
        for (int i = 20; i >= 0; -- i){
            ans += 1 << i;
            if (ans >= n || lst+info[ans] >= kth) ans -= 1 << i;
            else lst += 1 << i;
        }
        return ans+1;
    }
};

void solve(){
    using Yint = fenwick<i64>;
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    vector <int> own(n), dep(n);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ma = 0;
    auto dfs_create = [&](auto &&self, int u, int presor, int id)->void{
        dep[u] = dep[presor] + 1;
        own[u] = id;
        fmax(ma, dep[u]);
        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u, id);
        }
    };

    const int rt = 0;
    int tot = 0;
    vector <Yint> Ys;
    for (auto &v : g[rt]){
        ma = 0;
        dfs_create(dfs_create, v, rt, tot++);
        Yint Y(ma);
        Ys.push_back(Y);
    }

    i64 rt_v = 0;
    Yint Yrt(n);

    for (int i = 0, opt,val,u,d; i < q; ++ i){
        cin >> opt;
        if (opt == 0){
            cin >> u >> val >> d;
            u -= 1;
            if (u == rt){
                Yrt.update(1, val), Yrt.update(d+1, -val);
                rt_v += val;
            } else {
                int id = own[u];
                if (dep[u] <= d){
                    rt_v += val;
                    Yrt.update(1, val), Yrt.update(d-dep[u]+1, -val);
                    Ys[id].update(d-dep[u]+1, val), Ys[id].update(d+dep[u]+1, -val);
                } else {
                    Ys[id].update(dep[u]-d, val), Ys[id].update(dep[u]+d+1, -val);
                }
            }
        } else {
            cin >> u;
            u -= 1;
            if (u == rt){
                cout << rt_v << "\n";
            } else {
                i64 ans = Ys[own[u]].query(dep[u]) + Yrt.query(dep[u]);
                cout << ans << "\n";
            }
        }
    }
}
