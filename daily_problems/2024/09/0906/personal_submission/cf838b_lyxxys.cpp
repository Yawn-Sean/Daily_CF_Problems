#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, inf = 1e9, Pi = acos(-1.0);
struct Edge {
    int to, len;
};
// down[i] 是 1 到 i 的向下距离, up[i] 是 i 到 1 的 第一距离
struct Tree {
    vector <long long> down, Min, Tag;
    vector <int> up;
    // tag 维护 修改 down数组 的 懒标记
    Tree(){}
    Tree(int n): up(4*n), down(4*n), Min(4*n), Tag(4*n){}
    void pull(int u){
        Min[u] = min(Min[2*u], Min[2*u+1]);
    }
    void apply(int u, long long tag){
        Tag[u] += tag, Min[u] += tag;
    }
    void push(int u){
        apply(2*u, Tag[u]), apply(2*u+1, Tag[u]);
        Tag[u] = 0;
    } 
    // 区间加
    void modify1(int u, int l, int r, int pl, int pr, long long val){
        assert(l <= r);
        if (pl >= l && pr <= r){
            apply(u, val);
            return;
        }
        if (Tag[u]) push(u);
        int mid = pl + pr >> 1;
        if (mid >= l) modify1(u*2, l, r, pl, mid, val);
        if (mid < r) modify1(u*2+1, l, r, mid+1, pr, val);
        pull(u);
    }
    // 单点加
    void modify2(int u, int pos, int pl, int pr, long long val){
        if (pl == pr){
            up[u] += val;
            Min[u] = up[u] + down[u] + Tag[u];
            return;
        }
        if (Tag[u]) push(u);
        int mid = pl + pr >> 1;
        if (mid >= pos) modify2(u*2, pos, pl, mid, val);
        else modify2(u*2+1, pos, mid+1, pr, val);
        pull(u);
    }
    // 区间查询
    long long query(int u, int l, int r, int pl, int pr){
        assert(l <= r);
        if (pl >= l && pr <= r){
            return Min[u];
        }
        if (Tag[u]) push(u);
        int mid = pl+pr >> 1;
        long long mins = 1e18;
        if (mid >= l) mins = query(2*u, l, r, pl, mid);
        if (mid < r) mins = min(mins, query(2*u+1, l, r, mid+1, pr));
        return mins;
    }
    long long find(int u, int pos, int pl, int pr){  //查询 dfs序是pos 的 down[pos]
        if (pl == pr){
            return down[u]+Tag[u];
        }
        if (Tag[u]) push(u);
        int mid = pl+pr >> 1;
        if (mid >= pos) return find(u*2, pos, pl, mid);
        else return find(u*2+1, pos, mid+1, pr);
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector <vector<Edge>> g(n+1);
    vector <int> L(n+1), R(n+1), up(n+1), Id(n+1);
    vector <long long> dist(n+1);
    vector <array<int,3>> edge(2*n-1);  //存边
    for (int i = 0, a,b,c; i < n-1; ++ i){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edge[i+1] = {a, b, c};
    }

    // 求dfs序， down数组
    int tot = 0;
    function<void(int, int)> dfs = [&](int x, int fa){
        L[x] = ++ tot;
        Id[tot] = x;
        for (auto &it : g[x]){
            int y = it.to, len = it.len;
            if (y == fa) continue;
            dist[y] = dist[x] + len;
            dfs(y, x);
        }
        R[x] = tot;
    };

    // 求up数组
    for (int i = 0, a,b,c; i < n-1; ++ i){
        cin >> a >> b >> c;
        if (a < b) swap(a, b);
        assert(b == 1);
        up[a] = c;
        edge[n+i] = {a, b, c};
    }
    dfs(1, -1);
    assert(tot == n);
    // 对dfs序 建树
    Tree Y(n);
    function<void(int,int,int)> build = [&](int u, int pl, int pr){
        if (pl == pr){
            Y.up[u] = up[Id[pl]], Y.down[u] = dist[Id[pl]];
            Y.Min[u] = Y.up[u] + Y.down[u];
            return;
        }
        int mid = pl + pr >> 1;
        build(u*2, pl, mid), build(u*2+1, mid+1, pr);
        Y.pull(u);
    };
    build(1, 1, n);
    while (q--){
        int opt, u, v, i, w;
        cin >> opt;
        if (opt == 1){
            // 修改操作
            cin >> i >> w;
            auto a = edge[i][0], b = edge[i][1];
            if (i <= n-1){
                // a 是 父节点, 修改 b子树 的所有down
                if (L[a] > L[b]) swap(a, b);
                auto Disb = edge[i][2];
                Y.modify1(1, L[b], R[b], 1, n, w-Disb);  // 区间修改
                edge[i][2] = w;
            } else {
                assert(b == 1);
                auto ups = edge[i][2];
                Y.modify2(1, L[a], 1, n, w-ups);  //单点修改 !!!就是这里脑抽脑抽L[a]写了ID[a], 调了2小时 
                edge[i][2] = w;
            }
            assert(edge[i][2] <= 1000000);
        } else {
            cin >> u >> v;
            // 查询 down_u 和 down_v
            auto Du = Y.find(1, L[u], 1, n), Dv = Y.find(1, L[v], 1, n);
            // 如果 v 在 u 的 子树
            if (L[v] >= L[u] && L[v] <= R[u]){
                cout << Dv-Du << "\n";
            } else {
                // 查询子树的最小的 down_x + up_x
                auto mins = Y.query(1, L[u], R[u], 1, n);
                // cout << u << " " << mins << " " << Du << " " << Dv << " " << "\n";
                cout << mins + Dv-Du << "\n";
            }
        }
    }

}
