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

struct Node {
    int v;
    LL w;
};
constexpr int N = 2e5 + 5;
int n;
vector<Node> e[N];
bitset<N> vis;

int siz[N], tot;
void size(int u, int fa) {
    ++tot, siz[u] = 1;
    for (auto [v, w] : e[u])
        if (!vis[v] && v != fa) {
            size(v, u);
            siz[u] += siz[v];
        }
}
int f[N], root;
void dp(int u, int fa) {
    f[u] = tot - siz[u];
    for (auto [v, w] : e[u])
        if (!vis[v] && v != fa) {
            updmx(f[u], siz[v]);
            dp(v, u);
        }
    if (f[u] < f[root]) root = u;
}
void calc_vals(int u, int fa, LL w_pre, auto &&vals) {
    for (auto [v, w] : e[u]) {
        if (!vis[v] && v != fa) {
            w += w_pre;
            vals.push_back(w);
            calc_vals(v, u, w, vals);
        }
    }
}

constexpr int P = 62;
constexpr LL inf = 4e18;
vector<array<LL, 2>> pivots;
void calc(int u, int p = P) {
    tot = 0;
    size(u, 0);
    root = u;
    dp(u, 0);
    tot = 0;
    size(root, 0);
    vector<vector<LL>> vals;
    vals.reserve(e[root].size());
    multiset<LL> st;
    for (auto [v, w] : e[root])
        if (!vis[v]) {
            vals.push_back({w});
            vals.back().reserve(siz[v]);
            calc_vals(v, root, w, vals.back());
            for (auto x : vals.back()) st.insert(x);
        }
    dbg(root, vals);
    int i = 0, j_max = 0;
    for (auto [v, w] : e[root])
        if (!vis[v]) {
            for (auto x : vals[i]) st.extract(x);
            for (auto x : vals[i]) {
                bool brk = 0;
                for (int j = 1; j < p; ++j) {
                    auto it = st.lower_bound((1ll << j) - x);
                    bool flag = 0;
                    if (it != st.end()) {
                        updmn(pivots[j][1], x + (*it));
                        flag = 1;
                    }
                    if (it != st.begin()) {
                        --it;
                        const LL y = x + (*it);
                        if (y >= (1ll << (j - 1))) {
                            updmx(pivots[j][0], x + (*it));
                            flag = 1;
                        }
                    }
                    if (!flag) {
                        updmx(j_max, j);
                        brk = 1;
                        break;
                    }
                }
                if (!brk) j_max = p - 1;
                {
                    using ull = unsigned long long;
                    const int b = bit_width<ull>(ull(x));
                    for (int j = max(1, b - 2); j <= min(P - 1, b + 2); ++j) {
                        if (x >= (1ll << j)) updmn(pivots[j][1], x);
                        if (x <= (1ll << j)) updmx(pivots[j][0], x);
                    }
                    updmx(j_max, b + 1);
                }
            }
            for (auto x : vals[i]) st.insert(x);
            ++i;
        }
    clr(vals);
    // j_max = P - 1; // for LOCAL test only
    if (j_max != 0) {
        vis[root] = 1;
        for (auto [v, w] : e[root])
            if (!vis[v]) {
                calc(v, j_max + 1);
            }
    }
}

template <bool first = false>
void solve() {
    if constexpr (first == false) {
        for (int i = 1; i <= n; ++i) clr(e[i]);
    }
    vis.reset();
    pivots.assign(P, {-inf, inf});
    int Q;
    cin >> n >> Q;
    bool has1 = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        if (w == 1) has1 = 1;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    calc(1);
    vector<LL> opt;
    opt.reserve(P * 2);
    for (int i = 1; i < P; ++i) {
        if (pivots[i][0] != -inf) opt.push_back(pivots[i][0]);
        if (pivots[i][1] != inf) opt.push_back(pivots[i][1]);
    }
    sort(all(opt));
    opt.erase(unique(all(opt)), opt.end());
#ifdef LOCAL
    for (int i = 1; i < P; ++i) {
        if (pivots[i][0] == -inf && pivots[i][1] == inf) continue;
        dbg(i, pivots[i]);
    }
    dbg(opt);
#endif
    string ans(Q, '0');
    for (int i = 0; i < Q; ++i) {
        LL x;
        cin >> x;
        if (x == 1 && has1)
            ans[i] = '1';
        else {
            auto it = lower_bound(all(opt), x);
            if (it != opt.end() && (*it) <= x * 2) {
                ans[i] = '1';
            }
        }
    }
    cout << ans << "\n";
}
int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    solve<true>();
    for (int i = 1; i < t; ++i) solve();
    return 0;
}

/*
我们把整个条件分成 [1,2] [2,4] [4,8] [8,16] ...
然后我们观察这些分界点, [2,4,8,16,...]
任意的 [K,2K] 肯定会包含至少一个分界点
所以对于每个分界点 x, 我们只要找到原树里 min(>=x) 和 max(<=x) 就可以
那这怎么找呢 ?
力大砖飞, 直接点分治 !!!
1 需要特殊处理一下
*/
