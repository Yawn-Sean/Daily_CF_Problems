#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> G(n);
    for (int i = 0; i < n; ++i) cin >> G[i];
    vector<vector<int>> d(n, vector<int>(n, inf));
    d[0][0] = G[0][0] != 'a';
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        auto b = G[i][j] != 'a';
        if (i) d[i][j] = min(d[i][j], d[i-1][j] + b);
        if (j) d[i][j] = min(d[i][j], d[i][j-1] + b);
    }
    pair<int, int> s[4040], t[4040], *p, *q;
    int pp = 0, pq = 0;
    int diag;
    for (diag = 2 * n - 2; diag >= 0; --diag) {
        for (int i = max(diag - n + 1, 0); i < n && i <= diag; ++i) {
            if (d[i][diag-i] <= k) s[pp++] = {i, diag-i};
        }
        if (pp) break;
    }
    string ans;
    ans.reserve(2 * n);
    for (int i = 0; i <= diag; ++i) ans.push_back('a');
    if (diag < 0) ans.push_back(G[0][0]), s[pp++] = {0, 0};
    p = s; q = t;
    set<pair<int, int>> st;
    while (true) {
        pq = 0;
        st.clear();
        for (int l = 0; l < pp; ++l) {
            auto [i, j] = p[l];
            if (i < n - 1) st.insert({i + 1, j});
            if (j < n - 1) st.insert({i, j + 1});
        }
        if (st.empty()) break;
        for (auto v: st) q[pq++] = v;
        sort(q, q + pq, [&](const auto &a, const auto &b) { return G[a.first][a.second] < G[b.first][b.second]; });
        char c = G[q->first][q->second];
        ans.push_back(c);
        auto it = q + pq;
        while (--it != q && G[it->first][it->second] > c);
        pq = it - q + 1;
        swap(p, q);
        swap(pp, pq);
    }
    println("{}", ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
