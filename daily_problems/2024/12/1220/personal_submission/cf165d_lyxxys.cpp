#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> struct fenwick{
    vector <T> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n) {}
    void init(){
        for (int i = 1; i <= n; ++ i){
            update(i, 1);
        }
    }
    void update(int x, T c){
        if (x <= 0) assert(0);
        while (x <= n){
            info[x] += c;
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
};
void solve(){
    using Yint = fenwick<int>;

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector <int> dep(n), deg(n), own(n), L(n), R(n);
    vector <i64> egs;

    int rt = 0;
    for (int i = 0; i < n-1; ++ i){
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        egs.push_back(1ll*u*n + v);
        g[u].push_back(i);
        g[v].push_back(i);
        deg[u] += 1, deg[v] += 1;
        if (deg[u] > deg[rt]) rt = u;
        if (deg[v] > deg[rt]) rt = v;
    }

    int order = 0;
    auto dfs = [&](auto &&self, int u, int presor, int rt_id, int &ma)->void{
        // cout << u << "\n";
        L[u] = ++ order;
        dep[u] = dep[presor] + 1;
        own[u] = rt_id;
        fmax(ma, dep[u]);
        for (auto &id : g[u]){
            int v = (egs[id]/n+egs[id]%n) - u;
            if (v == presor) continue;
            self(self, v, u, rt_id, ma);
        }
        R[u] = order;
    };
    vector <Yint> Ys;
    int tot = -1;
    for (auto &id : g[rt]){
        int v = (egs[id]/n+egs[id]%n) - rt, siz = 0;
        dfs(dfs, v, rt, ++ tot, siz);
        Yint Y(siz);
        Y.init();
        Ys.push_back(Y);
    }
    R[rt] = order;

    auto chge = [&](int rt_id, int j, int c)->void{  // 深度就是在树状数组的编号
        Ys[rt_id].update(j, c);
    };
    auto ask = [&](int rt_id, int i)->bool{
        return Ys[rt_id].query(i) == i;
    };

    int m;
    cin >> m;
    for (int i = 0; i < m; ++ i){
        int opt, id, a, b;
        cin >> opt;
        if (opt == 1){
            cin >> id;
            id -= 1;
            a = egs[id]/n, b = egs[id]%n;
            chge(max(own[a], own[b]), max(dep[a], dep[b]), 1);
        } else if (opt == 2){
            cin >> id;
            id -= 1;
            a = egs[id]/n, b = egs[id]%n;
            chge(max(own[a], own[b]), max(dep[a], dep[b]), -1);
        } else {
            cin >> a >> b;
            a -= 1, b -= 1;
            if (a == rt && b == rt){
                cout << 0 << "\n";
                continue;
            }

            bool jg = 1;
            int ans = 0;
            if (L[a] > L[b]) swap(a, b);
            if (L[b] >= L[a] && L[b] <= R[a]){
                assert(dep[b] >= dep[a]);
                int rt_id = max(own[a], own[b]);
                jg = (Ys[rt_id].query(dep[b])-Ys[rt_id].query(dep[a]) == dep[b]-dep[a]);
                if (jg) ans = dep[b]-dep[a];
            } else {
                if (a != rt) jg &= ask(own[a], dep[a]);
                if (b != rt) jg &= ask(own[b], dep[b]);
                if (jg) ans = dep[a]+dep[b];
            }
            cout << (jg ? ans : -1) << "\n";
        }
    }
}
