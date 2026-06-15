#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include <local/dbg.h>
#else
    #define dbg(...) 42
#endif

using LL = long long;

// clang-format off
#define ai(x) using ai##x = array<int, x>;
ai(2); ai(3); ai(4); ai(5); ai(6); ai(7); ai(8); ai(9); ai(10); ai(26);
#undef ai
// clang-format on

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
template <class T>
inline bool updmx(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool updmn(T &x, const T &y) { return y < x ? x = y, 1 : 0; }
template <class T>
inline void clr(T &x) { T().swap(x); }

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return rng() % (r - l + 1) + l; }

constexpr int root = 1;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    int sp = 0;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (++u == 1) ++sp;
        if (++v == 1) ++sp;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> dep(n + 1), fa(n + 1), siz(n + 1), son(n + 1, -1);
    auto dfs1 = [&](auto &&self, int u, int pre) -> void {
        if (pre != -1) dep[u] = dep[pre] + 1;
        fa[u] = pre, siz[u] = 1;
        for (auto v : e[u]) {
            if (v == pre) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
        }
    };
    dfs1(dfs1, root, -1);
    vector<int> dfn(n + 1), dfn_inv(n + 2), top(n + 1);
    int timStamp = 0;
    auto dfs2 = [&](auto &&self, int u, int t) -> void {
        dfn[u] = ++timStamp, dfn_inv[timStamp] = u, top[u] = t;
        if (son[u] == -1) return;
        self(self, son[u], t);
        for (auto v : e[u]) {
            if (v == fa[u] || v == son[u]) continue;
            self(self, v, v);
        }
    };
    dfs2(dfs2, root, root);
    auto LCA = [&](int u, int v) -> int {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    };
    auto dis = [&](int u, int v) -> int {
        return dep[u] + dep[v] - dep[LCA(u, v)] * 2;
    };
    int u = 1, v = 2, ans = n;
    for (int x = 3; x <= n; ++x) {
        int dux = dis(u, x);
        int dvx = dis(v, x);
        int duv = dis(u, v);
        dbg(u, v, x, dux, dvx, duv);
        if (dux + dvx == duv) // x 已经在链 u-v 上
            ;
        else if (dux >= dvx) { // 尝试用 x 替换 v
            if (duv + dvx == dux) {
                v = x;
            } else {
                ans = x - 1;
                break;
            }
        } else { // dux < dvx，尝试用 x 替换 u
            if (duv + dux == dvx) {
                u = x;
            } else {
                ans = x - 1;
                break;
            }
        }
    }
    cout << ans;
    for (int i = 1; i < sp; ++i) cout << " 1";
    for (int i = 1; i < n - sp; ++i) cout << " 0";
    cout << "\n";
}
int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/*
给定树上的一条链 (由两个端点确定)
判断一个点
- 是否在链上
- 如果不是, 是拓展链还是形成三叉状
*/
