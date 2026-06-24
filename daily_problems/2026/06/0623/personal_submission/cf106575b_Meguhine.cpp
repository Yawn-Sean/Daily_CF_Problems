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
    LL d;
    int u;
    friend bool operator<(const Node &x, const Node &y) {
        return x.d > y.d;
    }
};

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, m, K;
    LL C;
    cin >> n >> m >> K >> C;
    vector<int> crowded(K);
    vector<int> flag(n + 1);
    for (int i = 0; auto &x : crowded) {
        cin >> x;
        flag[x] = ++i;
    }
    vector<int> F(n + 1);
    for (int i = 1; i <= n; ++i) cin >> F[i];
    const int tot = n + K;
    vector<vector<ai2>> e(tot + 1);
    for (auto u : crowded) {
        e[u].push_back({n + flag[u], F[u]});
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (flag[u] && flag[v])
            continue;
        else if (!flag[u] && !flag[v]) {
            e[u].push_back({v, 0});
            e[v].push_back({u, 0});
        } else {
            if (flag[u]) swap(u, v);
            e[u].push_back({v, 0});
            e[n + flag[v]].push_back({u, 0});
        }
    }
    priority_queue<Node> q;
    constexpr LL INF = 4e18;
    vector<LL> dp(tot + 1, INF);
    q.emplace(dp[1] = 0, 1);
    while (q.size()) {
        auto [d, u] = q.top();
        q.pop();
        if (dp[u] != d) continue;
        for (auto [v, w] : e[u]) {
            if (updmn(dp[v], d + w)) {
                q.emplace(dp[v], v);
            }
        }
    }
    if (dp[n] > C)
        cout << "-1";
    else
        cout << dp[n];
    return 0;
}
